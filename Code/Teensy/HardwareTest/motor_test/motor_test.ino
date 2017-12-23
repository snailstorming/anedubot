#include "DRV8835_teensy3.h"
#include <Encoder.h>


DRV8835 driveMotors(32, 30, 31, 29);

Encoder lwEnc(26, 25);
Encoder rwEnc(28, 27);

void setup()
{
  Serial.begin(9600);
  driveMotors.init(23437);
  
  long endTicksLeft = lwEnc.read();
  long endTicksRight = rwEnc.read();
  
  Serial.print("Left");
  Serial.println(endTicksLeft);
  Serial.print("Right");
  Serial.println(endTicksRight);
  


  driveMotors.setSpeeds(75,75);
  delay(500);
  driveMotors.setSpeeds(0,0);
  delay(500);
  
  driveMotors.setSpeeds(-75,-75);
  delay(500);
  driveMotors.setSpeeds(0,0);
  delay(500);
  
  driveMotors.setSpeeds(75,-75);
  delay(500);
  driveMotors.setSpeeds(0,0);
  delay(500);
  
  driveMotors.setSpeeds(-75,75);
  delay(500);
  driveMotors.setSpeeds(0,0);


  endTicksLeft = lwEnc.read();
  endTicksRight = rwEnc.read();
  
  Serial.print("Left");
  Serial.println(endTicksLeft);
  Serial.print("Right");
  Serial.println(endTicksRight);
  
}

void loop() {

}
