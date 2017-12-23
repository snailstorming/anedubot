#define LIDAR_PIN 8

#include <Servo.h>

Servo myservo;

int pos = 0;

void setup() {
  myservo.attach(LIDAR_PIN);
  myservo.write(90);
}

void loop() {
  
}

