#include <Servo.h>

Servo Servo1;
Servo Servo2;
Servo Servo_base; 

int joyXValue1;
int joyXValue2;
int joyYValue;
int Speed;

void setup() {
  Serial.begin(9600);     
}

void loop() {
  joyXValue1 = analogRead(A0);
  joyYValue = analogRead(A1);
  joyXValue2 = analogRead(A2);

  Xdirect1();
  Xdirect2();
  Ydirect();  

  delay(10); 
}

void Xdirect1(){
  if (joyXValue1 >= 400 && joyXValue1 <= 600) { 
    Servo1.detach();
  } else {
    Servo1.attach(9);
    if (joyXValue1 > 600){
      Servo1.write(100);
    } else {
      Servo1.write(80);
    }
  }
}

void Xdirect2(){
  if (joyXValue2 >= 400 && joyXValue2 <= 600) { 
    Servo2.detach();
  } else {
    Servo2.attach(10);
    if (joyXValue2 > 600){
      Servo2.write(80);
    } else {
      Servo2.write(100);
    }
  }
}

void Ydirect(){
  if (joyYValue >= 400 && joyYValue <= 600) { 
    Servo_base.detach();
  } else {
    Servo_base.attach(12);
    if (joyYValue > 600){
      Servo_base.write(105);
    } else {
      Servo_base.write(75);
    }
  }
}

