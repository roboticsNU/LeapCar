//by Yelenov Amir

import processing.serial.*;
import de.voidplus.leapmotion.*;
LeapMotion leap;
Serial myPort;

void setup() {
  size(800, 500);
  background(255);
  leap = new LeapMotion(this);
  println(Serial.list()[0]);
  myPort = new Serial(this, "COM3", 9600); //put your arduino port here
}

void leapOnConnect() {
  println("I connected!");
}

void draw() {
  background(255);
  for (Hand hand : leap.getHands()) {      
    pushMatrix();
    float handSize = hand.getSphereRadius();
    float yaw = hand.getYaw();
    float pitch = hand.getPitch();
    if(handSize>125 && yaw > 30 ){
      myPort.write(1); // motor is on and hand directs right
      println("1");
    }
    else 
      if(handSize>125 && yaw < -30 ){
      myPort.write(2); // motor is on and hand directs left
      println("2");
      } 
    else 
      if(pitch < -30){
      myPort.write(3); // motor is on and hand directs front
      println("3");
      }
    else 
      if(pitch > 30){
      myPort.write(4); // motor is on and hand directs back
      println("4");
      } 
    else 
      if(handSize < 125 ){
      myPort.write(5); // motor is off
      println("5");
      } 
    println(handSize, yaw);
    popMatrix();
  }
}
