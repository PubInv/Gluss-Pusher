
int Ppos = 7;
int Pneg = 6;
int Qpos = 5;
int Qneg = 4;

// In fact Speed is not used with relays
int FULLSPEED = 255;

const int ACTIVATION_TIME = 500;


// This is the model of our actuator.
// P is the position of the P coil in 1/2" increments.
int p = 0;
// Q is the position of the Q coil in 1/2" increments.
// By structure, Q = P + 3
int q() {
  return p+3;
}
// The polarity of any position is given by this funciton...
// +1 means North to the right, -1 means South to the right (postive x), 0 means unstable.
// Someday this could be a continuous function....if we every try to get continuos
// resolutin from our 2-coil system.
// The period of polarity is 4 (in half inches).
int polarity(int pos) {
  int modpos = pos % 4;
  switch(modpos) {
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
  pinMode(Ppos,OUTPUT);
  pinMode(Pneg,OUTPUT);
  pinMode(Qpos,OUTPUT);
  pinMode(Qneg,OUTPUT);
  Serial.begin(9600);
}


void stop()//
{
 
}

void activate(int coil,int direction,int strength) {
  if (coil == 0) {
    if (direction == 1) {
      // Just to be sure we will make sure other is turned off!
      digitalWrite(Pneg,LOW);
      delay(10);
      digitalWrite(Ppos,HIGH);   
    } else if (direction == -1) {
      // Just to be sure we will make sure other is turned off!
      digitalWrite(Ppos,LOW);
      delay(10);
      digitalWrite(Pneg,HIGH);   
    }
  } else if (coil == 1) {
    if (direction == 1) {
      // Just to be sure we will make sure other is turned off!
      digitalWrite(Qneg,LOW);
      delay(10);
      digitalWrite(Qpos,HIGH);   
    } else if (direction == -1) {
      // Just to be sure we will make sure other is turned off!
      digitalWrite(Qpos,LOW);
      delay(10);
      digitalWrite(Qneg,HIGH);   
    }
  }
}
void deactivate(int coil) {
  if (coil == 0) {
      digitalWrite(Ppos,LOW);
      digitalWrite(Pneg,LOW);
  } else {
      digitalWrite(Qpos,LOW);
      digitalWrite(Qneg,LOW);
  }
   
}
// This is an experimental attempt to move fast and smoothly
// by modifying activation time.
void moveHalfInches(int n, int s) {
  int kickstart_time = 70;
  int duration_time = 40;
  int end_time = 70;
  if (n > 0) {
    moveHalfInch(s,kickstart_time);
  }
  for(int i = 1; i < n-1; i++) {
    moveHalfInch(s,duration_time);
  }
  if (n > 1) {
    for(int i = n-1; i < n;i++) {
      moveHalfInch(s,end_time);
    }
  }
  
}

// Now, to move half an inch, we have 
// to deside which coil has polarity.
// We then push that coil according to the polarity, and 
// update the position.
// Positive means move right, negative means move left.
void moveHalfInch(int s,int activation_time) {
  // 0 means the P Coil, 1 means the Q Coil.
  int coilWithPolarity = (polarity(p) == 0) ? 1 : 0;
  int polarityOfCoil = (coilWithPolarity) ? polarity(q()) : polarity(p);
  
  Serial.print("p = ");
  Serial.println(p);
  
  Serial.print("polariy of Coil ");
  Serial.println(polarityOfCoil);
  Serial.print("Activation Coil: ");
  Serial.println(coilWithPolarity);
  Serial.print("In direction:");
  Serial.println(s*polarityOfCoil);   
  activate(coilWithPolarity,s*polarityOfCoil,FULLSPEED);
  delay(activation_time);
  deactivate(coilWithPolarity); 
  
  // Now make the model reflect the update
  p += s;
}

int playCnt = 0;

void experiment1() {
    for(int i = 0; i < 6; i++) {
      Serial.print("i = ");
      Serial.println(i);
      for(int j = 0; j < i+1; j++) {
        moveHalfInch(1,ACTIVATION_TIME);
        delay(10);
      }
      for(int k = 0; k < i+1; k++) {
         moveHalfInch(-1,ACTIVATION_TIME);
         delay(10);
      }
    }
}
  
void experiment2() {
  for(int i = 0; i < 6; i++ ) {

    moveHalfInches(4+i,1);
    delay(1000);
    moveHalfInches(4+i,-1);
    delay(1000);
  }
}

void loop() {
  
  if (playCnt < 1) {
    playCnt++;
    experiment2();
  
  }

}
