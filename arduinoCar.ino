//by Yelenov Amir

#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int val;
int IN1 = 5;
int IN2 = 4;
int IN3 = 3;
int IN4 = 2;
int ENA = 9;
int ENB = 10;
Servo myservo;
void setup() {
  myservo.attach(7);  
  Serial.begin(9600);
  myservo.write(45);
  pinMode (ENA, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (IN3, OUTPUT);
}
void loop() {
  val = Serial.read();  
  if(val == 1){ //right
    delay(500);
    myservo.write(25);
    digitalWrite (IN4, HIGH);
    digitalWrite (IN3, LOW);
    analogWrite (ENB, 100);
  }
  if (val == 2){ //left
    delay(500);
    myservo.write(65);
    digitalWrite (IN4, HIGH);
    digitalWrite (IN3, LOW); 
    analogWrite (ENB, 100);
  }

  if (val == 3){ //forward
    delay(500);
    myservo.write(45);
    digitalWrite (IN4, HIGH);
    digitalWrite (IN3, LOW);
    analogWrite (ENB, 100);
  }
  if (val == 4){ //backward
    delay(500);
    myservo.write(45);
    digitalWrite (IN3, HIGH);
    digitalWrite (IN4, LOW);
    analogWrite (ENB, 100);
  }

  if (val == 5){ //stop
    digitalWrite (IN4, HIGH);
    digitalWrite (IN3, LOW);
    delay(500);
    myservo.write(45);
    analogWrite (ENB, 0);
  }
Serial.println(val);
}
