#include <Servo.h>

int pinRedLed = 13;
int pinGreenLed = 23;
int pinBuzzer = 22;
int bluetooth = 1;
int pinLeftLF = 2;
int pinCenterLF = 3;
int pinRightLF = 4;
int pinLeftAO = 5;
int pinCenterOF = 6;
int pinRightOF = 7;
int pinLidarServo = 8;
int pinClampServo = 9;

int posLidar;
int posClamp;

bool sRedLed;
bool sGreenLed;
bool sServoClamp;

Servo servoLidar;
Servo servoClamp;

void setup() {
  Serial.begin(9600);
  pinMode(pinRedLed, OUTPUT);
  pinMode(pinGreenLed, OUTPUT);

  servoLidar.attach(pinLidarServo);
  servoClamp.attach(pinClampServo); 


  sRedLed = LOW;
  sGreenLed = LOW;

  delay(1000);

  posLidar = 90;
  servoLidar.write(posLidar);

  posClamp = 70;
  servoClamp.write(posClamp);

  sServoClamp = LOW;

  Serial.println("Test program");
  Serial.println(" 1. Red led");
  Serial.println(" 2. Green led");
  Serial.println(" 3. Buzzer");
  Serial.println(" 4. Lidar servo");
  Serial.println(" 5. Clamp servo");
}

void loop() {
  if (Serial.available() > 0) { 
    int inByte = Serial.read();
    
    switch (inByte) {
      
      case '1':
        if (sRedLed == LOW){
          digitalWrite(pinRedLed, HIGH);
          sRedLed = HIGH;
        }
        else{
          digitalWrite(pinRedLed, LOW);
          sRedLed = LOW;
        }
        
        break;
        
      case '2':
        if (sGreenLed == LOW){
          digitalWrite(pinGreenLed, HIGH);
          sGreenLed = HIGH;
        }
        else{
          digitalWrite(pinGreenLed, LOW);
          sGreenLed = LOW;
        }
              
        break;
        
      case '3':
        tone(pinBuzzer,2637,100);
        delay(150);
        tone(pinBuzzer,2637,100);
        delay(300);
        tone(pinBuzzer,2637,100);
        delay(300);
        tone(pinBuzzer,2093,100);
        delay(100);
        tone(pinBuzzer,2637,100);
        delay(300);
        tone(pinBuzzer,3136,100);
        delay(550);
        tone(pinBuzzer,1568,100);
        delay(575);
        
        break;

      case '4':
        posLidar = 90;
        for (posLidar = 90; posLidar <= 180; posLidar += 1){
          servoLidar.write(posLidar);
          delay(15);
        }
        for (posLidar = 180; posLidar >= 0; posLidar -= 1){
          servoLidar.write(posLidar);
          delay(15);
        }
        for (posLidar = 0; posLidar <= 90; posLidar += 1){
          servoLidar.write(posLidar);
          delay(15);
        }        
      
        break;
        
      case '5':
        posClamp = 70;
        servoClamp.write(posClamp);

        if (sServoClamp == LOW){

          posClamp = 160;
          servoClamp.write(posClamp);
          delay(150);
          posClamp = 166;
          servoClamp.write(posClamp);          
       
          sServoClamp = HIGH;
        }
        else{
          posClamp = 70;
          servoClamp.write(posClamp); 
          
          sServoClamp = LOW;
        }

        break;
        
      case '6':
      
        break;                
      case '7':
        break;
      case '8':
        break;                
      case '9':
        break;                

    } // switch
  } // void loop
  
}
