//. Motor driver shield- 2012 Copyright (c) Seeed Technology Inc.
// 
//  Original Author: Jimbo.we
//  Contribution: LG
//  
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

// Modified by Rob Read to control the Linear Actuator...

int pinI1=8;//define I1 interface

int pinI2=11;//define I2 interface 
int speedpinA=9;//enable motor A
int pinI3=12;//define I3 interface 
int pinI4=13;//define I4 interface 
int speedpinB=10;//enable motor B
int spead =127;//define the spead of motor
const int FULLSPEED = 255;
int moveRightPin = 2;
int moveLeftPin = 3;

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
  pinMode(pinI1,OUTPUT);
  pinMode(pinI2,OUTPUT);
  pinMode(speedpinA,OUTPUT);
  pinMode(pinI3,OUTPUT);
  pinMode(pinI4,OUTPUT);
  pinMode(speedpinB,OUTPUT);
  pinMode(moveRightPin,INPUT);
  pinMode(moveLeftPin,INPUT);
  Serial.begin(9600);
}


void stop()//
{
     digitalWrite(speedpinA,LOW);// Unenble the pin, to stop the motor. this should be done to avid damaging the motor. 
     digitalWrite(speedpinB,LOW);
     delay(1000);
 
}

void activate(int coil,int direction,int strength) {
  if (coil == 0) {
    analogWrite(speedpinA,strength);
  } else if (coil == 1) {
    analogWrite(speedpinB,strength);
  }
  if (coil == 0) {
    if (direction == 1) {
      digitalWrite(pinI2,LOW);
      digitalWrite(pinI1,HIGH);     
    } else if (direction == -1) {
      digitalWrite(pinI2,HIGH);
      digitalWrite(pinI1,LOW);   
    }
  } else if (coil == 1) {
    if (direction == 1) {
      digitalWrite(pinI4,LOW);
      digitalWrite(pinI3,HIGH);     
    } else if (direction == -1) {
      digitalWrite(pinI4,HIGH);
      digitalWrite(pinI3,LOW);   
    }
  }
}
void deactivate(int coil) {
  if (coil == 0) 
    digitalWrite(speedpinA,LOW);
  if (coil == 1)
    digitalWrite(speedpinB,LOW);
}

bool toggle = false;

// Now, to move half an inch, we have 
// to deside which coil has polarity.
// We then push that coil according to the polarity, and 
// update the position.
// Positive means move right, negative means move left.
void moveHalfInch(int s) {
  // 0 means the P Coil, 1 means the Q Coil.
  int coilWithPolarity = (polarity(p) == 0) ? 1 : 0;
  int polarityOfCoil = (coilWithPolarity) ? polarity(q()) : polarity(p);
  
  Serial.print("polariy of Coil ");
  Serial.println(polarityOfCoil);
  Serial.print("Activation Coil: ");
  Serial.println(coilWithPolarity);
  Serial.print("In direction:");
  Serial.println(s*polarityOfCoil);   
  activate(coilWithPolarity,s*polarityOfCoil,FULLSPEED);
  delay(400);
  deactivate(coilWithPolarity); 
  
  // Now make the model reflect the update
  p += s;
}


void moveLeftCand1() {
  int activatedir = toggle ? -1 : 1;
  activate(1,activatedir,FULLSPEED);
  // Let's wait 1/10 of a second to take affect.
  delay(200);
  activate(0,activatedir,FULLSPEED);
  toggle = !toggle;
  delay(200);
  deactivate(1);
  delay(300);
  deactivate(0);
}
void moveRightCand1() {
  int activatedir = toggle ? 1 : -1;
  activate(1, activatedir ,FULLSPEED);
  // Let's wait 1/10 of a second to take affect.
  delay(200);
  activate(0,activatedir,FULLSPEED);
  toggle = !toggle;
  delay(200);
  deactivate(1);
  delay(300);
  deactivate(0);
}




void TestButtons()
{
  int valRight = digitalRead(moveRightPin);
  if (valRight == LOW) {
   Serial.println("Moving Right");    
    moveHalfInch(1);
  }
  int valLeft = digitalRead(moveLeftPin);
  if (valLeft == LOW) {
    Serial.println("Moving Left");    
    moveHalfInch(-1);
  }
 deactivate(0);
 deactivate(1);
}

void loop() {
  TestButtons();
  delay(200);
}
