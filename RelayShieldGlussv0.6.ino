#include <stdlib.h>
#include <EEPROM.h>
#include <assert.h>

int Ppos = 7;
int Pneg = 6;
int Qpos = 5;
int Qneg = 4;

int ANALOG_PIN_P = 0;
int ANALOG_PIN_Q = 1;
int ANALOG_PIN_POT = 5;
const int ANALOG_VOLTAGE = 3;

// Calibratio[x] is meant to be the voltage read from our position sensor
// and position x.  At present, there is some confustion about what the
// Position "p" really means. My goal is to standardize "p == 0" to mean
// "Fully retracted".  I actually need to clean up the language of much of this file.

const int NUM_POSITIONS = 14; // This will be rougly the 2 x the number of magnets in the current approach.
int Calibration[14];


// In fact Speed is not used with relays
int FULLSPEED = 255;



// This a relative position.  I am attempting
// to move toward an absolute position.
// This is the model of our actuator.
// P is the position of the P coil in 1/2" increments.
int p = 0;
// Q is the position of the Q coil in 1/2" increments.
// By structure, Q = P + 3
int q() {
  return p + 3;
}

// apos represents our current understanding of our digital 
// position (measured in 1/2" intervals, with 0 being full retraction.
int apos = 0;

int compute_p_from(int apos) {
  int px;
  px = apos % 4;
//  px = px + 0;
//  px = px + 1;
//  px = px + 2;
//  px = px + 3;
  return px; 
}

void set_calibration_to_hand_code() {
  Calibration[0] = 325;
  Calibration[1] = 365;
  Calibration[2] = 401;
  Calibration[3] = 438;
  Calibration[4] = 471;
  Calibration[5] = 506;
  Calibration[6] = 528;
  Calibration[7] = 552;
  Calibration[8] = 573;
  Calibration[9] = 594;
  Calibration[10] = 613;
  Calibration[11] = 633;
  Calibration[12] = 649;
  Calibration[13] = 665;
}
// Here we update our two model variables by reading our sensor position...
void update_model() {
   int val = sensePosition();
   int dpos = digitizePosition(val);
   apos = dpos;
   p = compute_p_from(apos);
}

// The polarity of any position is given by this funciton...
// +1 means North to the right, -1 means South to the right (postive x), 0 means unstable.
// Someday this could be a continuous function....if we every try to get continuos
// resolutin from our 2-coil system.
// The period of polarity is 4 (in half inches).
int polarity(int pos) {
  while (pos < 0) pos += 1000;
  int modpos = pos % 4;
  //  Serial.print("Position:");
  //  Serial.println(pos);
  //  Serial.println("Modpos:");
  //  Serial.println(modpos);
  switch (modpos) {
    case 0:
      return 0;
    case 1:
      return 1;
    case 2:
      return 0;
    case 3:
      return -1;
  }

}


void setup()
{
  pinMode(Ppos, OUTPUT);
  pinMode(Pneg, OUTPUT);
  pinMode(Qpos, OUTPUT);
  pinMode(Qneg, OUTPUT);
  pinMode(ANALOG_PIN_P, INPUT);
  pinMode(ANALOG_PIN_Q, INPUT);
  pinMode(ANALOG_VOLTAGE, INPUT);
  Serial.begin(38400);
  // We want to read the eeprom calibration...
  getCalibration();
  dumpCalibration();
}


void stop()//
{

}

void activate(int coil, int direction, int strength) {
  if (coil == 0) {
    if (direction == 1) {
      // Just to be sure we will make sure other is turned off!
      digitalWrite(Pneg, LOW);
      delay(10);
      digitalWrite(Ppos, HIGH);
    } else if (direction == -1) {
      // Just to be sure we will make sure other is turned off!
      digitalWrite(Ppos, LOW);
      delay(10);
      digitalWrite(Pneg, HIGH);
    }
  } else if (coil == 1) {
    if (direction == 1) {
      // Just to be sure we will make sure other is turned off!
      digitalWrite(Qneg, LOW);
      delay(10);
      digitalWrite(Qpos, HIGH);
    } else if (direction == -1) {
      // Just to be sure we will make sure other is turned off!
      digitalWrite(Qpos, LOW);
      delay(10);
      digitalWrite(Qneg, HIGH);
    }
  }
}
void deactivate(int coil) {
  if (coil == 0) {
    digitalWrite(Ppos, LOW);
    digitalWrite(Pneg, LOW);
  } else {
    digitalWrite(Qpos, LOW);
    digitalWrite(Qneg, LOW);
  }

}
// This is an experimental attempt to move fast and smoothly
// by modifying activation time.
const float TIME_MULTIPLE = 2.0;
void moveHalfInches(int n, int s) {
  if (n == 0) return;
  int kickstart_time = 200 * TIME_MULTIPLE;
  int duration_time = 200 * TIME_MULTIPLE;
  int end_time = 200 * TIME_MULTIPLE;
  //  int kickstart_time = 5000;
  //  int duration_time = 500;
  //  int end_time = 500;
  if (n > 0) {
    moveHalfInch(s, kickstart_time);
  }
  for (int i = 1; i < n - 1; i++) {
    moveHalfInch(s, duration_time);
  }
  if (n > 1) {
    for (int i = n - 1; i < n; i++) {
      moveHalfInch(s, end_time);
    }
  }
  int val = analogRead(ANALOG_VOLTAGE);
  Serial.print("VOLTAGE = ");
  Serial.println(val);
}

// Now, to move half an inch, we have
// to deside which coil has polarity.
// We then push that coil according to the polarity, and
// update the position.
// Positive means move right, negative means move left.
void moveHalfInch(int s, int activation_time) {
  moveHalfInchOpenLoop(s, activation_time);
  //  moveHalfInchClosedLoop(s,activation_time);
  return;
}
void moveHalfInchOpenLoop(int s, int activation_time) {
  // 0 means the P Coil, 1 means the Q Coil.
  int coilWithPolarity = (polarity(p) == 0) ? 1 : 0;
  int polarityOfCoil = (coilWithPolarity) ? polarity(q()) : polarity(p);

  Serial.print("p = ");
  Serial.print(p);
  Serial.print(" C: ");
  Serial.print(coilWithPolarity);
  Serial.print(" s:");
  Serial.println(s * polarityOfCoil);
  activate(coilWithPolarity, s * polarityOfCoil, FULLSPEED);
  delay(activation_time);
  deactivate(coilWithPolarity);

  // Now make the model reflect the update
//  p += s;
  update_model();
}




int playCnt = 0;

const int ACTIVATION_TIME = 500;


void experiment2() {
  for (int i = 0; i < 6; i++ ) {

    moveHalfInches(4 + i, 1);
    delay(100);
    moveHalfInches(4 + i, -1);
    delay(100);
  }
}

void experiment3() {
  if (Serial.available()) {
    char inChar = Serial.read();
    Serial.println(inChar);
    while (!Serial.available() > 0) ;
    if (inChar == 'l' || inChar == 'r') {
      int n = Serial.parseInt();
      Serial.println(n);
      Serial.println("About to call!");
      Serial.println((inChar == 'l') ? -1 : 1);
      moveHalfInches(n, (inChar == 'l') ? -1 : 1);
      //     holdPosition(500);
    }
    while (Serial.read() == '\n') ;
  }
}

// void moveToPosition(int newp) {
//  int d = newp - p;
//  Serial.print("About to call moveHalfInches");
//  Serial.println((int)d);
//  moveHalfInches((int)abs(d), (d < 0) ? -1 : 1);
// }

void moveToPosition(int newp) {
  if (newp < 0) {
    Serial.println(newp);
    Serial.println("Can't retract to negative value!");
    newp = 0;
  }
  if (newp >= NUM_POSITIONS) {
    Serial.println(newp);
    Serial.println("Can't extend to that value!");
    newp = NUM_POSITIONS-1;
  }
  int val = sensePosition();
  int dpos = digitizePosition(val);
  apos = dpos;
  int i = 0;
  do { 
    int d = newp - apos;
    moveHalfInches((int)abs(d), (d < 0) ? -1 : 1);
    int val = sensePosition();
    int dpos = digitizePosition(val);
    apos = dpos;
    i++;
    Serial.print("i = ");
    Serial.println(i);
  } while (i < 1 && newp != apos);
}

void experiment4() {
  if (Serial.available() > 0) {
    char inChar = Serial.read();
    Serial.println(inChar);
    while (Serial.available() == 0) ;
    if (inChar == 'p') {
      int n = Serial.parseInt();
      Serial.println(n);
      moveToPosition(n);
    }
    while (Serial.read() == '\n') ;
  }
}

// Read "samples" number of samples into array for
// averaging for
void read_for_time(int ms, int pin, int array[]) {
  long start = millis();
  long cnt = 0;
  long sum = 0;
  long weight = 0;
  while (cnt < ms) {
    int val = analogRead(pin);
    weight++;
    sum += val;
    long tm = millis();
    if (tm > cnt + start) {
      for (int i = 0; i < tm - (cnt + start); i++) {
        array[cnt] = (sum / weight);
      }
      sum = 0;
      weight = 0;
    }
    cnt = tm - start;
  }
}

void output_sampled_array(int ms, int pin, int msPerOutput) {
  int tarray[ms];
  for (int i = 0; i < ms; i++ ) {
    tarray[i] = 0;
  }
  read_for_time(ms, pin, tarray);
  long sum = 0;
  long cnt = 0;
  for (int i = 0; i < ms; i++) {
    sum += tarray[i];
    cnt++;
    if (cnt >= (ms / msPerOutput)) {
      if ((sum / cnt) > 0) {
        Serial.print(i);
        Serial.print(" ");
        Serial.println(sum / cnt);
      }
      sum = 0;
      cnt = 0;
    }
  }

}

// Move half inch, using closed loop mechanism...
// we will read the in active coil in order observe that we have
// successfully moved.
boolean seemsToHaveMoved(int timeseries[], int len) {
  const int GATE = 100;
  int cnt = 0;
  for (int i = 0; i < len; i++) {
    if (timeseries[i] >= GATE) {
      cnt++;
    }
  }
  // This is a terrible test, but I'll do it for now
  Serial.println("Returning:");
  Serial.println(cnt > 5);
  return cnt > 5;
}
void moveHalfInchClosedLoop(int s, int activation_time) {
  // 0 means the P Coil, 1 means the Q Coil.
  int coilWithPolarity = (polarity(p) == 0) ? 1 : 0;
  int polarityOfCoil = (coilWithPolarity) ? polarity(q()) : polarity(p);

  activate(coilWithPolarity, s * polarityOfCoil, FULLSPEED);

  // now let's do activeation_time sampling....
  int tarray[activation_time];
  for (int i = 0; i < activation_time; i++ ) {
    tarray[i] = 0;
  }

  // This is similar to delay....
  read_for_time(activation_time,
                coilWithPolarity ? ANALOG_PIN_P : ANALOG_PIN_Q, tarray);

  for (int i = 0; i < activation_time; i++) {
    Serial.print(i);
    Serial.print(" ");
    Serial.println(tarray[i]);
  }
  //  if (seemsToHaveMoved(tarray,activation_time)) {
  // Now make the model reflect the update
  deactivate(coilWithPolarity);
 // p += s;
  update_model();

}

int toggle = 1;
void experiment5() {
  moveHalfInchClosedLoop(toggle, 600);
}

// We will repeatably read and print our values.
void experiment6() {
  output_sampled_array(100, ANALOG_PIN_P, 10);
  toggle = (toggle == 1) ? -1 : 1;
}

// Let's create a pot
const int NUM_POT_CLICKS = 17;
void experiment7() {
  int val = analogRead(ANALOG_PIN_POT);

  Serial.println("INPUT");
  Serial.println(val);
  // Now map 0 - 1023 range into 17 positsions from +9 to -7.
  int rawpos = (val * NUM_POT_CLICKS) / 1023;
  // now treat the the extreme as -7 to represent the maximal
  // position for the Q coil.
  int pos = 10 - rawpos;

  Serial.println(pos);
  Serial.println("XXXX");
  moveToPosition(pos);
}

// This is a funny little function---I want to turn the
// coils on to "Hold" the current position for a certain
// number of milliseconds.  This can be used to resist a
// minor force.
void holdPosition(int ms) {
  // 0 means the P Coil, 1 means the Q Coil.
  int coilWithPolarity = (polarity(p) == 0) ? 1 : 0;
  int coilCentered = (coilWithPolarity == 0) ? 1 : 0;
  int polarityOfUnstableCoil = (coilWithPolarity) ? polarity(q()) : polarity(p);


  Serial.print("p = ");
  Serial.println(p);

  Serial.print("polariy of Unstable Coil ");
  Serial.println(polarityOfUnstableCoil);
  Serial.print("Activation Coil: ");
  Serial.println(coilWithPolarity);
  Serial.print("In direction:");
  Serial.println(-polarityOfUnstableCoil);
  activate(coilCentered, -polarityOfUnstableCoil, FULLSPEED);
  delay(ms);
  deactivate(coilCentered);

  Serial.print("AFTER val =");
  Serial.println(readPositionVoltage());
  update_model();
}

// This is active in the sense of actively 
// watching our position, and trying to stay there.
// However, it doesn't activate the coils unless it senses
// that we are out of position.
void smartHoldPosition(int pos,int s) {
   long start = millis();
   while ((millis() - start) < s * 1000) {
     int rpos = digitizePosition(readPositionVoltage());
     if (rpos != pos) {
       moveToPosition(pos);
     }
   }
}

// Note: if we used a transistor, we could turn off the LED when in
// Sleep mode.  This would be a significant benefit.
int readPositionVoltage() {
  int val = analogRead(ANALOG_VOLTAGE);
  Serial.println(val);
  return val;
}

void wobble() {
  moveHalfInches(1, 1);
  moveHalfInches(1, 1);
  moveHalfInches(1, 1);
  moveHalfInches(1, 1);
  moveHalfInches(1, -1);
  moveHalfInches(1, -1);
  moveHalfInches(1, -1);
  moveHalfInches(1, -1);
}

// Now we will attempt to do a complete calibration...this
// is an ACTIVE calibration, not a passive calibration, which
// I hope will come later.
void calibrate() {
  wobble();
  // Now let us attempt to retract completely...
// moveHalfInches(20, -1);
  // but that might bounce, so let's tighten it up...
  
  // This is creating a problem becasue of course we are out of sync and 
  // bumping up against the peg. I could move until the sensing quits going down...
  // Also I really need a red/green LED as just a "something went wrong" maybe 3 or or 4!
  
  // if we can't get back in 100 steps, we have an error condition!!!
  int cur = readPositionVoltage();
  bool limit = false;
  for(int i = 0; i < 100 && !limit; i++) {
    moveHalfInches(1,-1);
    int val = readPositionVoltage();
    if (val >= cur) { // either we are at the fence or something has gone wrong!
      limit = true;
      // Probably we now have an off-by-one error, so we modify p
      // A actually need to work this value out, for now this is just trial and erroro!
       p = 0;
    //   p = 1;
      // p = 2;
      // p = 3;
    } else {
      cur = val;
    }  
  }
  
  // now let us try to move and Calibrate...
  for (int i = 0; i < NUM_POSITIONS; i++) {
    // Ideally we would read WHILE we were holding, but that is an improvement
    holdPosition(200);
    int val = readPositionVoltage();
    Calibration[i] = val;
     moveHalfInches(1, 1);
  }
  dumpCalibration();
}

void dumpCalibration() {
  for (int i = 0; i < NUM_POSITIONS; i++) {
    Serial.print(i);
    Serial.print(" ");
    Serial.println(Calibration[i]);
  }
}

void putCalibration() {
  for (int i = 0; i < NUM_POSITIONS; i++) {
    EEPROM.put(i * sizeof(int), Calibration[i]);
  }
}
void getCalibration() {
  for (int i = 0; i < NUM_POSITIONS; i++) {
    EEPROM.get(i * sizeof(int), Calibration[i]);
  }
}

// Check that a Calibration is monotonically increasing or
boolean monotoneCalibrationP() {
  for (int i = 0; i < NUM_POSITIONS - 1; i++) {
    if (Calibration[i] >= Calibration[i + 1]) {
      return false;
    }
  }
  return true;
}

// convert a position sensor reading into the
// closest digital position based on the current Calibaration table
int digitizePosition(int v) {
  // for now let's just do a linear lookup...
  // we assume the calibration is monotone...
  if (!monotoneCalibrationP()) {
    Serial.println("Calibration not monotone!");
    Serial.println("Cowardly refusing to digitize this positions.");
    return -1;
  }
  for (int j = 0; j < NUM_POSITIONS-1; j++) {
     if (Calibration[j] >= v) {
        if (j == 0) {
          return 0;
        }
        int dh = abs(Calibration[j]-v);
        int dl = abs(Calibration[j-1]-v);
        return (dh > dl) ? j-1 : j;
     }
    }
  return NUM_POSITIONS-1;
}
void testDigitizePosition() {
  int start = Calibration[0] - 10;
  int finish = Calibration[NUM_POSITIONS-1] + 10;
  for (int i = start; i < finish; i++) {
    int v = digitizePosition(i);
    Serial.print(i);
    Serial.print(" ");
    Serial.println(v);  
  }
}
int sensePosition() {
  int val = analogRead(ANALOG_VOLTAGE);
  return val;
}
// main_controller is my attempt to make a versitile
// reader from the serial port to control the
// variety of functions that we have.
// lx: move "left" by x half-inches.
// rx: move "right" by x half-inches.
// w: wobble!
// hx: hold position for x seconds
// c: calibrate!
// f: Have fun by moving the pushod back and forth
// s: read the current position
// z: write the calibartion to the EEProm
// g: get the calibration from the EEProm into memory
// d: dump Calibration
// t: test Digitize Positions
// a: set calibration to hand-coded calibration
void main_controller() {
  if (Serial.available()) {
    bool terminator_not_found = true;
    char inChar = Serial.read();
    Serial.println(inChar);
    if (inChar == 'l' || inChar == 'r') {
      int n = Serial.parseInt();
      Serial.println(n);
      Serial.println("About to call!");
      Serial.println((inChar == 'l') ? -1 : 1);
      moveHalfInches(n, (inChar == 'l') ? -1 : 1);
    }
    if (inChar == 'p') {
      int n = Serial.parseInt();
      Serial.println(n);
      moveToPosition(n);
    }
    if (inChar == 'w') {
      wobble();
    }
    if (inChar == 'd') {
      dumpCalibration();
    }
    if (inChar == 'h') {
      int n = Serial.parseInt();
      Serial.println(n);
      smartHoldPosition(digitizePosition(readPositionVoltage()),20);
    }
    if (inChar == 'f') {
      experiment2();
    }
    if (inChar == 'c') {
      calibrate();
    }
    if (inChar == 't') {
      testDigitizePosition();
    }
    if (inChar == 's') {
      int val = sensePosition();
      Serial.print("Position Voltage: ");
      Serial.println(val);
      int dpos = digitizePosition(val);
      Serial.print("Digital Position: ");
      Serial.println(dpos);
      apos = dpos;
      Serial.print("Relative Position: ");
      Serial.println(p);
      p = apos % 4;
    }
    if (inChar == 'z') {
      dumpCalibration();
      putCalibration();
    }
    if (inChar == 'g') {
      getCalibration();
      dumpCalibration();
    }
    if (inChar == 'a') {
      set_calibration_to_hand_code();
    }
    if (inChar == '\n') {
      terminator_not_found = false;
    }
    if (terminator_not_found) {
    while (!Serial.available()) ;
    char terminator = Serial.read();
    if (terminator != '\n') {
      Serial.print(terminator);
      Serial.println(" : Didn't read terminator successfully.");
    }
    }
  }
}


void loop() {
  //if (playCnt < 1) {
  playCnt++;
  main_controller();
  // }

}
