#include <Servo.h>

#include <Wire.h>
#include "Pixy.h"
#include <Adafruit_MotorShield.h>
Pixy pixy;
Servo cage;
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); // Create the motor shield object
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);  // Declare our motor ports
Adafruit_DCMotor *myMotor4 = AFMS.getMotor(4);
Adafruit_DCMotor *myMotor3 = AFMS.getMotor(3);
int yVars[100];
int last = 1;
int grig = 0;
int x = pixy.blocks[1].x;
int y = pixy.blocks[1].y;
uint16_t blocks;
int poje = 2;
int preet = 2;
unsigned long plooj;
unsigned long greeg;
int groop;
void setup()
{
  AFMS.begin();
  pixy.init();
  cage.attach(10);
  cage.write(130);
}
void backwards (int roit, int loit) {
  myMotor1->run(RELEASE);
  myMotor4->run(RELEASE);
  myMotor3->run(RELEASE);
  myMotor4->setSpeed(roit / 2);
  myMotor4->run(BACKWARD);
  myMotor3->setSpeed(loit / 2);
  myMotor3->run(FORWARD);
  delay(250);
  myMotor4->setSpeed(roit);
  myMotor4->run(BACKWARD);
  myMotor3->setSpeed(loit);
  myMotor3->run(FORWARD);
}
void straight (int roit, int loit) {
  myMotor1->run(RELEASE);
  myMotor4->run(RELEASE);
  myMotor3->run(RELEASE);
  myMotor4->setSpeed(roit / 2);
  myMotor4->run(FORWARD);
  myMotor3->setSpeed(loit / 2);
  myMotor3->run(BACKWARD);
  delay(50);
  myMotor4->setSpeed(roit);
  myMotor4->run(FORWARD);
  myMotor3->setSpeed(loit);
  myMotor3->run(BACKWARD);
}
void yeet () {
  myMotor1->run(RELEASE);
  myMotor4->run(RELEASE);
  myMotor3->run(RELEASE);
  myMotor1->setSpeed(0);
  myMotor1->run(BACKWARD);
  myMotor4->setSpeed(0);
  myMotor4->run(FORWARD);
  myMotor3->setSpeed(0);
  myMotor3->run(FORWARD);
  //delay(10);
}
void SpinRight (int pew) {
  myMotor1->setSpeed(pew);
  myMotor1->run(BACKWARD);
  myMotor4->setSpeed(pew);
  myMotor4->run(BACKWARD);
  myMotor3->setSpeed(pew);
  myMotor3->run(BACKWARD);
}
void SpinLeft (int pewpew) {
  myMotor1->setSpeed(pewpew);
  myMotor1->run(FORWARD);
  myMotor4->setSpeed(pewpew);
  myMotor4->run(FORWARD);
  myMotor3->setSpeed(pewpew);
  myMotor3->run(FORWARD);
}
void track (int ident) {
  if (pixy.blocks[ident].height * pixy.blocks[ident].width > 19) {
    if (pixy.blocks[ident].x > 0 && pixy.blocks[ident].x <= 75) {
      straight(240, 105);
    }
    if (pixy.blocks[ident].x > 75 && pixy.blocks[ident].x <= 150) {
      straight(240, 135);
    }
    if (pixy.blocks[ident].x < 170 && pixy.blocks[ident].x > 150) {
      straight(185, 185);
    }
    if (pixy.blocks[ident].x < 250 && pixy.blocks[ident].x >= 170) {
      straight(135, 185);
    }
    if (pixy.blocks[ident].x < 320 && pixy.blocks[ident].x >= 250) {
      straight(105, 240);
    }
  }
}
void seenBallz () {
  if (blocks) {
    track(0);
  }
  else { //if (pixy.blocks[1].signature!=1 && pixy.blocks[0].signature!=1){
    yeet();
    delay(200);
    if (blocks) {}
      
      
    else {
      if (pixy.blocks[0].height * pixy.blocks[0].width > 19) {
      SpinRight(40);
      delay(125);
      yeet();
      cage.write(70);
      poje = 1;
    }
  }
  }
}
void seenBall () {
  if (blocks) {
    track(1);
  }
  else { //if (pixy.blocks[1].signature!=1 && pixy.blocks[0].signature!=1){
    yeet();
    delay(200);
    if (blocks) {}
      
      
    else {
      if (pixy.blocks[1].height * pixy.blocks[1].width > 19) {
      SpinRight(40);
      delay(125);
      yeet();
      cage.write(70);
      poje = 1;
    }
  }
  }
}
void seenHome () {
  if (blocks) {
    track(1);
  }
  else { //if (pixy.blocks[1].signature!=1 && pixy.blocks[0].signature!=1){
    yeet();
    delay(200);
    if (blocks) {}
      
    
    else {
      if (pixy.blocks[1].height * pixy.blocks[1].width > 19) {
      SpinLeft(40);
      delay(250);
      yeet();
      cage.write(130);
      preet = 1;
      backwards(200, 200);
      delay(500);
      yeet();
      delay(8309482348092);
    }
  }
  }
}
void seenHomez () {
  if (blocks) {
    track(0);
  }
  else { //if (pixy.blocks[1].signature!=1 && pixy.blocks[0].signature!=1){
    yeet();
    delay(200);
    if (blocks) {}
      
    
    else {
      if (pixy.blocks[0].height * pixy.blocks[0].width > 19) {
      SpinLeft(40);
      delay(250);
      yeet();
      cage.write(130);
      preet = 1;
      backwards(200, 200);
      delay(500);
      yeet();
      delay(8309482348092);
    }
  }
  }
}
void loop() {

  blocks = pixy.getBlocks();
  if (poje == 2) {
    SpinLeft(40);
    if (pixy.blocks[0].signature == 1 || pixy.blocks[1].signature == 1) {
      if (pixy.blocks[0].signature == 1) {
        seenBallz();
      }
      if (pixy.blocks[1].signature == 1) {
        seenBall();
      }
    }
  }
  if (poje == 1) {
    if (preet == 2) {
      SpinRight(40);
      if (pixy.blocks[0].signature == 2 || pixy.blocks[1].signature == 2) {
        if (pixy.blocks[0].signature == 2) {
          seenHomez();
        }
        if (pixy.blocks[1].signature == 2) {
          seenHome();
        }
      }
    }
  }
}





