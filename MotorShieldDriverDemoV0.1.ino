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
// Note this file is very hard to understand without understanding the physical geometry and 
// circuit which I have built --- but it DOES at least demonstrate using the shield.

int pinI1=8;//define I1 interface
int pinI2=11;//define I2 interface 
int speedpinA=9;//enable motor A
int pinI3=12;//define I3 interface 
int pinI4=13;//define I4 interface 
int speedpinB=10;//enable motor B
int spead =127;//define the spead of motor
const int FULLSPEED = 255;
 
void setup()
{
  pinMode(pinI1,OUTPUT);
  pinMode(pinI2,OUTPUT);
  pinMode(speedpinA,OUTPUT);
  pinMode(pinI3,OUTPUT);
  pinMode(pinI4,OUTPUT);
  pinMode(speedpinB,OUTPUT);
}
/*
void forward()
{
     analogWrite(speedpinA,spead);//input a simulation value to set the speed
     analogWrite(speedpinB,spead);
     digitalWrite(pinI4,HIGH);//turn DC Motor B move clockwise
     digitalWrite(pinI3,LOW);
     digitalWrite(pinI2,LOW);//turn DC Motor A move anticlockwise
     digitalWrite(pinI1,HIGH);
}
void backward()//
{
     analogWrite(speedpinA,spead);//input a simulation value to set the speed
     analogWrite(speedpinB,spead);
     digitalWrite(pinI4,LOW);//turn DC Motor B move anticlockwise
     digitalWrite(pinI3,HIGH);
     digitalWrite(pinI2,HIGH);//turn DC Motor A move clockwise
     digitalWrite(pinI1,LOW);
}
void left()//
{
     analogWrite(speedpinA,spead);//input a simulation value to set the speed
     analogWrite(speedpinB,spead);
     digitalWrite(pinI4,HIGH);//turn DC Motor B move clockwise
     digitalWrite(pinI3,LOW);
     digitalWrite(pinI2,HIGH);//turn DC Motor A move clockwise
     digitalWrite(pinI1,LOW);
}
void right()//
{
     analogWrite(speedpinA,spead);//input a simulation value to set the speed
     analogWrite(speedpinB,spead);
     digitalWrite(pinI4,LOW);//turn DC Motor B move anticlockwise
     digitalWrite(pinI3,HIGH);
     digitalWrite(pinI2,LOW);//turn DC Motor A move clockwise
     digitalWrite(pinI1,HIGH);
}
*/

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

void moveLeftCand1() {
  activate(1,1,FULLSPEED);
  // Let's wait 1/10 of a second to take affect.
  delay(100);
  activate(0,1,FULLSPEED);
  delay(100);
  deactivate(1);
  delay(300);
}
void moveRightCand1() {
  activate(1,-1,FULLSPEED);
  // Let's wait 1/10 of a second to take affect.
  delay(100);
  activate(0,-1,FULLSPEED);
  delay(100);
  deactivate(1);
  delay(300);
}

// Note in fact the behavior of this in the circuit that I 
// created does NOT move left and right, but moves continually LEFT
// or RIGHT depending ont he polarity of the way I attach the second coil!
void loop()
{
  moveLeftCand1();
  delay(1000);
  moveRightCand1();
  delay(1000);
}
