//EDIT : Adafruit_SSD1306.h
//Windows OS: C:\Users\Jordi Guerrero\Dropbox\github\anedubot\Code\Teensy\HardwareTest\Screen\Adafruit_ssd1306 (73-75 line)
//       #define SSD1306_128_64
//   // #define SSD1306_128_32
//   //#define SSD1306_96_16


#include <Servo.h>
#include <Adafruit_SSD1306.h>
#include "DRV8835_teensy3.h"

#include <Wire.h>
#include <VL53L0X.h>

#define pinRedLed     13
#define pinGreenLed   23
#define pinBuzzer     22
#define bluetooth     1
#define pinLeftLF     2
#define pinCenterLF   3
#define pinRightLF    4
#define pinLeftAO     5
#define pinCenterAO   6
#define pinRightAO    7
#define pinLidarServo 8
#define pinClampServo 9

#define OLED_MOSI   24
#define OLED_CLK    10
#define OLED_DC     11
#define OLED_CS     12
#define OLED_RESET  25

#define pinXshutL     17
#define pinXshutR     16

int dipPins[] = {26, 27, 28}; //DIP Switch Pins

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
DRV8835 driveMotors(32, 30, 31, 29);

VL53L0X sensorL;
VL53L0X sensorR;

int i;
int j;

int posLidar;
int posClamp;

bool sRedLed;
bool sGreenLed;
bool sServoClamp;

int sPinLeftLF;
int sPinCenterLF;
int sPinRightLF;
int sPinLeftAO;
int sPinCenterAO;
int sPinRightAO;

int robotId;

float dSensorL;
float dSensorR;

int xPoint;
int yPoint;

int starttime;
int endtime;

Servo servoLidar;
Servo servoClamp;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  display.clearDisplay();
  display.display();

//change VL53L0X address
  pinMode(pinXshutL, OUTPUT);
  pinMode(pinXshutR, OUTPUT);
  digitalWrite(pinXshutL, LOW);
  digitalWrite(pinXshutR, LOW);
  delay(500);
  Wire.begin();
  Serial.begin (9600);
  digitalWrite(pinXshutL, HIGH);
  delay(150);
  sensorL.init(true);
  delay(100);
  sensorL.setAddress((uint8_t)22);
  digitalWrite(pinXshutR, HIGH);
    delay(150);
  sensorR.init(true);
  delay(100);
  sensorR.setAddress((uint8_t)25);
//end change VL53L0X address  
//HIGH_SPEED
  sensorL.setMeasurementTimingBudget(20000);
  sensorR.setMeasurementTimingBudget(20000);

  driveMotors.init(23437);
  
  Serial.begin(9600);
  pinMode(pinRedLed, OUTPUT);
  pinMode(pinGreenLed, OUTPUT);

  for(i = 0; i<=2; i++){
    pinMode(dipPins[i], INPUT_PULLUP);      // sets the dipswitch pins as input
  }

  pinMode(pinLeftLF, INPUT);
  pinMode(pinCenterLF, INPUT);
  pinMode(pinRightLF, INPUT);
  pinMode(pinLeftAO, INPUT);
  pinMode(pinCenterAO, INPUT);
  pinMode(pinRightAO, INPUT);

  servoLidar.attach(pinLidarServo);
  servoClamp.attach(pinClampServo); 
  
  sRedLed = LOW;
  sGreenLed = LOW;


  delay(2000); //It is needed to show the text in Serial (throught USB) connection
  //WHO AM I
  for(i=0; i<=2; i++){
  j = (j << 1) | digitalRead(dipPins[i]);   // read the input pin
  }
  robotId = abs(j-7);
  Serial.print("I am :");
  Serial.println(robotId);
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello, world!");
  display.setCursor(0,15);
  display.println("I am : Robot ");
  display.setCursor(80,15);
  display.println(robotId);
  display.display();


  //delay(1000);

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
  Serial.println(" 6. Avoid Obstacles");
  Serial.println(" 7. Lidars");
  Serial.println(" 8. Mapping");
}

void loop() {
  if (Serial.available() > 0) { 
    int inByte = Serial.read();
    
    switch (inByte) {
      case '0':
        Serial.println("Test program");
        Serial.println(" 1. Red led");
        Serial.println(" 2. Green led");
        Serial.println(" 3. Buzzer");
        Serial.println(" 4. Lidar servo");
        Serial.println(" 5. Clamp servo");
        Serial.println(" 6. Avoid Obstacles");
        Serial.println(" 7. Lidars");
        Serial.println(" 8. Mapping");
        
        break;
      
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

        sPinLeftAO = digitalRead(pinLeftAO);
        sPinCenterAO = digitalRead(pinCenterAO);
        sPinRightAO = digitalRead(pinRightAO);
        starttime = millis();
        endtime = starttime;
        Serial.println("Start avoid obstacle test");
        while ((endtime - starttime) <=10000)
        {

          if ((sPinCenterAO) || (sPinLeftAO) || (sPinRightAO)){
            driveMotors.setSpeeds(0,0);
          }
          if (!sPinCenterAO) {
            driveMotors.setSpeeds(-60,-40);
          }

          if (!sPinLeftAO){
            driveMotors.setSpeeds(-40,-60);
          }

          if (!sPinRightAO){
            driveMotors.setSpeeds(-80,-30);
          }
                    
          sPinLeftAO = digitalRead(pinLeftAO);
          sPinCenterAO = digitalRead(pinCenterAO);
          sPinRightAO = digitalRead(pinRightAO);
          delay(10);
          endtime = millis();
        }
        driveMotors.setSpeeds(0,0);
        Serial.println("End avoid obstacle test");
      
        break;                
      case '7':
        starttime = millis();
        endtime = starttime;
        while ((endtime - starttime) <=10000)
        {
          Serial.print(sensorL.readRangeSingleMillimeters());
          Serial.print(" : ");
          Serial.println(sensorR.readRangeSingleMillimeters());
          endtime = millis();
        }
        
        break;
      case '8':

          posLidar = 90;
          
          display.clearDisplay();
          display.drawPixel(63, 31, WHITE);
          display.display();
          
          for (posLidar = 90; posLidar <= 180; posLidar += 1){
            servoLidar.write(posLidar);
          
            dSensorL = sensorL.readRangeSingleMillimeters() / 10 ;
            //Serial.println(dSensorL);
            yPoint = int(-1*(dSensorL*sin(((float(posLidar)+30)* 71) / 4068))+31);
            xPoint = int(dSensorL*cos(((float(posLidar)+30)* 71) / 4068)+63);
            display.drawPixel(xPoint, yPoint, WHITE);
            
            dSensorR = sensorR.readRangeSingleMillimeters() / 10 ;
            //Serial.println(dSensorR);
            yPoint = int(-1*(dSensorR*sin(((float(posLidar)-30)* 71) / 4068))+31);
            xPoint = int(dSensorR*cos(((float(posLidar)-30)* 71) / 4068)+63);
            display.drawPixel(xPoint, yPoint, WHITE);
          
            display.display();
          }
          
          
          for (posLidar = 180; posLidar >= 0; posLidar -= 1){
            servoLidar.write(posLidar);
          
            dSensorL = sensorL.readRangeSingleMillimeters() / 10 ;
            //Serial.println(dSensorL);
            yPoint = int(-1*(dSensorL*sin(((float(posLidar)+30)* 71) / 4068))+31);
            xPoint = int(dSensorL*cos(((float(posLidar)+30)* 71) / 4068)+63);
            display.drawPixel(xPoint, yPoint, WHITE);
            
            dSensorR = sensorR.readRangeSingleMillimeters() / 10 ;
            //Serial.println(dSensorR);
            yPoint = int(-1*(dSensorR*sin(((float(posLidar)-30)* 71) / 4068))+31);
            xPoint = int(dSensorR*cos(((float(posLidar)-30)* 71) / 4068)+63);
            display.drawPixel(xPoint, yPoint, WHITE);
          
            display.display();
          }
          for (posLidar = 0; posLidar <= 90; posLidar += 1){
            servoLidar.write(posLidar);
          
            dSensorL = sensorL.readRangeSingleMillimeters() / 10 ;
            //Serial.println(dSensorL);
            yPoint = int(-1*(dSensorL*sin(((float(posLidar)+30)* 71) / 4068))+31);
            xPoint = int(dSensorL*cos(((float(posLidar)+30)* 71) / 4068)+63);
            display.drawPixel(xPoint, yPoint, WHITE);
            
            dSensorR = sensorR.readRangeSingleMillimeters() / 10 ;
            //Serial.println(dSensorR);
            yPoint = int(-1*(dSensorR*sin(((float(posLidar)-30)* 71) / 4068))+31);
            xPoint = int(dSensorR*cos(((float(posLidar)-30)* 71) / 4068)+63);
            display.drawPixel(xPoint, yPoint, WHITE);
          
            display.display();
          } 
 
        break;                
      case '9':

        starttime = millis();
        endtime = starttime;
        Serial.println("Start line follower test");
        while ((endtime - starttime) <=10000)
        {      
          sPinLeftLF = digitalRead(pinLeftLF);
          sPinCenterLF = digitalRead(pinCenterLF);
          sPinRightLF = digitalRead(pinRightLF);
          
          display.clearDisplay();
          display.setTextSize(1);
          display.setTextColor(WHITE);
          display.setCursor(0,0);
          display.println(sPinLeftLF);
          display.setCursor(10,0);
          display.println(sPinCenterLF);
          display.setCursor(20,0);
          display.println(sPinRightLF);
          display.display();
          endtime = millis();
          delay(100);
        }
                        
        break;                

    } // switch
  } // void loop
  
}
