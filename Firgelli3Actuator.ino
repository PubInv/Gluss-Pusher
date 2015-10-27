#include <stdlib.h>
#include <EEPROM.h>
#include <math.h>
#include <assert.h>

int ANALOG_PIN_P = 0;
int ANALOG_PIN_Q = 1;
int ANALOG_PIN_POT = 5;
const int ANALOG_VOLTAGE = 3;

int sign(int a) {
  return (a < 0) ? -1 : ((a == 0) ? 0 : 1); 
}


int pinI1=8;//define I1 interface

int pinI2=11;//define I2 interface 
int speedpinA=9;//enable motor A
int pinI3=12;//define I3 interface 
int pinI4=13;//define I4 interface 
int speedpinB=10;//enable motor B
int spead =127;//define the spead of motor
const int FULLSPEED = 255;

// Chosen to deal with duty cycle
const int CRUISE_SPEED = 255;
int pinI5 = 2;
int pinI6 = 4;
int speedpinC = 3;

// This doesn't make much sense with the FirgelliController
int NUM_POSITIONS = 14;
int Calibration[14];

typedef struct {
  int forwardPin;
  int reversePin;
  int speedPin;
  int potPin;
  
  int minV = -99;
  int maxV = -99;
} actuator;

// typedef struct actuator Actuator;

actuator act[3];

// At present I will pack the calibrations into EEPROM starting at this address
int start_address = 0;

void setup()
{
  
act[0].forwardPin = pinI2;
act[0].reversePin = pinI1;
act[0].speedPin = speedpinA;
act[0].potPin = A0;

act[1].forwardPin = pinI4;
act[1].reversePin = pinI3;
act[1].speedPin = speedpinB;
act[1].potPin = A1;

act[2].forwardPin = pinI6;
act[2].reversePin = pinI5;
act[2].speedPin = speedpinC;
act[2].potPin = A2;


  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  
  pinMode(pinI1,OUTPUT);
  pinMode(pinI2,OUTPUT);
  pinMode(speedpinA,OUTPUT);
  pinMode(pinI3,OUTPUT);
  pinMode(pinI4,OUTPUT);
  pinMode(speedpinB,OUTPUT);
   pinMode(pinI5,OUTPUT);
  pinMode(pinI6,OUTPUT);
  pinMode(speedpinC,OUTPUT);
  
  Serial.begin(9600);
  // We want to read the eeprom calibration...
}


void stop()//
{
    digitalWrite(speedpinA,LOW);// Unenble the pin, to stop the motor. this should be done to avid damaging the motor. 
     digitalWrite(speedpinB,LOW);
     digitalWrite(speedpinC,LOW);
}
// 1 means extend, -1 means restract
void activate_actuators(int actuator,int direction,int strength)
{
  analogWrite(act[actuator].speedPin,strength);
    if (direction == 1) {
      digitalWrite(act[actuator].reversePin,LOW);
      digitalWrite(act[actuator].forwardPin,HIGH);     
    } else if (direction == -1) {
      digitalWrite(act[actuator].reversePin,HIGH);
      digitalWrite(act[actuator].forwardPin,LOW);   
    }
}

void deactivate_actuator(int actuator) {
     digitalWrite(act[actuator].speedPin,LOW);
}

void output_sampled_array(int ms, int pin, int msPerOutput) {
  int tarray[ms];
  for (int i = 0; i < ms; i++ ) {
    tarray[i] = 0;
  }
 // read_for_time(ms, pin, tarray);
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

// Note: if we used a transistor, we could turn off the LED when in
// Sleep mode.  This would be a significant benefit.
int readPositionVoltage() {
  int val = analogRead(ANALOG_VOLTAGE);
  Serial.println(val);
  return val;
}



void putCalibration() {
  for (int i = 0; i < 3; i++) {
    EEPROM.put(start_address + i * sizeof(actuator), act[i]);
  }
}
void getCalibration() {
  for (int i = 0; i < 3; i++) {
    EEPROM.get(start_address + i * sizeof(actuator), act[i]);
  }
}

void dumpCalibration() {
  for (int i = 0; i < 3; i++) {
    Serial.print(i);
    Serial.print(" ");
    Serial.println(act[i].minV);
    Serial.print(" + ");
    Serial.println(act[i].maxV);
  }
}

int sensePosition(int pin) {
  int val = analogRead(pin);
  return val;
}
// main_controller is my attempt to make a versitile
// reader from the serial port to control the
// variety of functions that we have.

void sensePositionVector(int v[]) {
  for(int i = 0; i < 3; i++) {
    v[i] = sensePosition(act[i].potPin);
  }
}
float dist(int a[],int b[]) {
  return sqrt((a[0] - b[0])*(a[0] - b[0]) + (a[1] - b[1])*(a[1] - b[1]) + (a[2] - b[2])*(a[2] - b[2]));
}
void OutputVector(int v[]) {
   for(int i = 0; i < 3; i++) {
     Serial.print(v[i]);
     Serial.print(" ");
   }
   Serial.println();
}

void move_vector(int *vec) {
  int cval[3];
  int dir[3];
 
 
  sensePositionVector(cval);
    const int tolerance = 50;
    const float STUCK_DISTANCE = 1.0; // millivolts  
  const int DELAY_TIME = 30;
  const int MAX_STUCK = 4;
    
    bool all_good = false;
  { // AAAA
   for(int i = 0; i < 3; i++) {
 //    dir[i] = sign(cval[i] - vec[i]);
    dir[i] = sign(vec[i] - cval[i]);
  }
  OutputVector(cval);
  Serial.println("Vector");
  OutputVector(dir);
  
  all_good = true;
     for(int i = 0; i < 3; i++) {
       if (abs(cval[i] - vec[i]) < tolerance) {
              deactivate_actuator(i);   
       } else {
           all_good = false;
       }
  }
 }


  int stuck_cnt = 0;

  while ((!all_good) && (stuck_cnt < MAX_STUCK)) {
    { // AAAA
     for(int i = 0; i < 3; i++) {
       // We can get stuck here and end up changing directions too often.  I need a better 
       // way of detecting that condition. We never really want to change directions more than once.
 //      dir[i] = sign(cval[i] - vec[i]);
     dir[i] = sign(vec[i] - cval[i]);      
       activate_actuators(i,dir[i],CRUISE_SPEED); 
     } 
     Serial.println("target:");
      OutputVector(vec);
       OutputVector(dir);
       OutputVector(cval);
     delay(DELAY_TIME); 
     int v[3];
     for(int i = 0; i < 3; i++) {
       v[i] = cval[i];     
     }
     
     sensePositionVector(cval);
     Serial.println(dist(v,cval));
     if (dist(v,cval) < STUCK_DISTANCE) {
       stuck_cnt++;
     } else {
       stuck_cnt = 0;
       Serial.println("ressetting stuck!");
     }
     
     
     OutputVector(cval);
     
     all_good = true;
     for(int i = 0; i < 3; i++) {
       if (abs(cval[i] - vec[i]) < tolerance) {
              deactivate_actuator(i);   
       } else {
           all_good = false;
       }
     }
    }
  }
  if (stuck_cnt >= MAX_STUCK) {
    Serial.println("GOT STUCK!");
  }

 for(int i = 0; i < 3; i++) {
    deactivate_actuator(i);
  }
  Serial.println("Move done!");
}

void test_via_extremes() {
  int v[3];
 for (int i = 0; i < 3; i++) {
   for (int j = 0; j < 3; j++) {
     for(int k = 0; k < 3; k++) {
       v[0] = i*500;
       v[1] = j*500;
       v[2] = k*500;
         move_vector(v);
         Serial.println("Made a move");
         OutputVector(v);
     }
   }
 }
}

// basic plan: Contract till you stop, record voltage
// then extend till you stop, record voltage!d
void calibrate(int actuator) {
 int val = sensePosition(act[actuator].potPin);
 const int DELAY_TIME = 5000;
 Serial.println(val);
 int cval = 1024;
 int dir = -1;
 while (val < cval) {
      activate_actuators(actuator,dir,255);
      delay(DELAY_TIME);
      deactivate_actuator(actuator);
      cval = val;
      val = sensePosition(act[actuator].potPin);
      Serial.println(val);
 } 
 act[actuator].minV = cval; 
  Serial.print("MinV = ");
 Serial.println(act[actuator].minV);
 
 dir = 1;
 cval = -1;
  while (val > cval) {
      activate_actuators(actuator,dir,255);
      delay(DELAY_TIME);
      deactivate_actuator(actuator);
      cval = val;
      val = sensePosition(act[actuator].potPin);
      Serial.println(val);
 } 
 act[actuator].maxV = cval; 
 

 Serial.print("MaxV = ");
 Serial.println(act[actuator].maxV);
 
}
// u0: actuator #0 open
// u1: actuator #0 stop
// u2: actuator #0 close
// v0: actuator #1 open
// v1: actuator #1 stop
// v2: actuator #1 close
void main_controller() {
  if (Serial.available()) {
    bool terminator_not_found = true;
    char inChar = Serial.read();
    Serial.println(inChar);
    // This stuff is for the MotorShield
    if (inChar == 'u' || inChar == 'v' || inChar == 'w') {
      int n = Serial.parseInt();
      int coil = (inChar == 'u') ? 0 : ((inChar == 'v') ? 1 : 2);
      if (n == 1) {
        deactivate_actuator(coil);
      } else {
      int dir = (n == 0) ? -1 : 1;
      Serial.println("Direction:");
      if (dir == 1) Serial.println("extend");
      if (dir == -1) Serial.println("retract");
      activate_actuators(coil,dir,255);
      }
    }
    
    if (inChar == 't') {
      for(int i = 0; i < 1; i++) {
       test_via_extremes();
      }
    }
    
    if (inChar == 'd') {
      dumpCalibration();
    }
    if (inChar == 'c') {
      int n = Serial.parseInt();
      if (n < 0 || n > 2) {
        Serial.println("bad actuator");
      } 
      calibrate(n);
    }
    if (inChar == 'r') {
      int n = Serial.parseInt();
      if (n < 0 || n > 2) {
        Serial.println("bad actuator");
      } 
      int val = sensePosition(act[n].potPin);
      Serial.print("value of ");
      Serial.print(act[n].potPin);
      Serial.print(" = ");
      Serial.println(val);
    }
    
      if (inChar == 'a') {
      char comma = Serial.read();
      int vec[3];
      vec[0] = Serial.parseInt();
      comma = Serial.read();
      vec[1] = Serial.parseInt();
      comma = Serial.read();
      vec[2] = Serial.parseInt();
      Serial.println("XXX");
      OutputVector(vec);
      move_vector(vec);
      OutputVector(vec);
    }
 
    if (inChar == 'z') {
      dumpCalibration();
      putCalibration();
    }
    if (inChar == 'g') {
      getCalibration();
      dumpCalibration();
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
  main_controller();

}
