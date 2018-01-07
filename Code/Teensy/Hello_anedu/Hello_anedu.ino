#include <Adafruit_SSD1306.h>
#include "DRV8835_teensy3.h"
#include <Encoder.h>

#define LED_RED     13
#define LED_GREEN   23

#define BUZZER  22

#define BUTTON1     21
#define BUTTON2     20

#define OLED_MOSI   24
#define OLED_CLK    10
#define OLED_DC     11
#define OLED_CS     12
#define OLED_RESET  25

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
DRV8835 driveMotors(32, 30, 31, 29);
Encoder lwEnc(15, 14);
Encoder rwEnc(36, 35);

int menu_pos;
long endTicksLeft = lwEnc.read();
long endTicksRight = rwEnc.read();

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  driveMotors.init(23437);

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  


  tone(BUZZER,2637,100);
  delay(150);
  tone(BUZZER,2637,100);
  delay(300);
  noTone(BUZZER);
  delay(500);
  
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED, HIGH);
  delay(500);
  digitalWrite(LED_RED, LOW);
  delay(500);
  digitalWrite(LED_RED, HIGH);
  delay(500);
  digitalWrite(LED_RED, LOW);

  menu_pos = 1;

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello, world!");
  display.setCursor(0,15);
  display.setTextColor(BLACK,WHITE);
  display.println("1. Motor test");
  display.setCursor(0,30);
  display.setTextColor(WHITE);
  display.println("2. Lidar test");
  display.display();

}

void loop() {
  
  if (digitalRead(BUTTON1) == LOW) {
    digitalWrite(LED_RED, HIGH);
    if (menu_pos == 1) {
      menu_pos = 2;
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("Hello, world!");
      display.setCursor(0,15);
      display.setTextColor(WHITE);
      display.println("1. Motor test");
      display.setCursor(0,30);
      display.setTextColor(BLACK,WHITE);
      display.println("2. Lidar test");
      display.display();      
    } else {
      menu_pos = 1;
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("Hello, world!");
      display.setCursor(0,15);
      display.setTextColor(BLACK,WHITE);
      display.println("1. Motor test");
      display.setCursor(0,30);
      display.setTextColor(WHITE);
      display.println("2. Lidar test");
      display.display(); 
    }
    delay(500);
  }
  else {
    digitalWrite(LED_RED, LOW);
  }
  if (digitalRead(BUTTON2) == LOW) {
    if (menu_pos == 1){

      endTicksLeft = lwEnc.read();
      endTicksRight = rwEnc.read();
      
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("MOTOR TEST");
      display.setCursor(0,15);
      display.println("Left Encoder");      
      display.setCursor(100,15);
      display.println(endTicksLeft);
      display.setCursor(0,30);
      display.println("Right Encoder");
      display.setCursor(100,30); 
      display.println(endTicksRight);
      display.display(); 
      
      driveMotors.setSpeeds(75,75);
      delay(500);
      driveMotors.setSpeeds(0,0);
      delay(500);
      
      endTicksLeft = lwEnc.read();
      endTicksRight = rwEnc.read();
      
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("MOTOR TEST");
      display.setCursor(0,15);
      display.println("Left Encoder");      
      display.setCursor(100,15);
      display.println(endTicksLeft);
      display.setCursor(0,30);
      display.println("Right Encoder");
      display.setCursor(100,30); 
      display.println(endTicksRight);
      display.display(); 

      delay(1000);
      
      driveMotors.setSpeeds(-75,-75);
      delay(500);
      driveMotors.setSpeeds(0,0);
      delay(500);

      endTicksLeft = lwEnc.read();
      endTicksRight = rwEnc.read();
      
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("MOTOR TEST");
      display.setCursor(0,15);
      display.println("Left Encoder");      
      display.setCursor(100,15);
      display.println(endTicksLeft);
      display.setCursor(0,30);
      display.println("Right Encoder");
      display.setCursor(100,30); 
      display.println(endTicksRight);
      display.display(); 

      delay(1000);      
      
      driveMotors.setSpeeds(75,-75);
      delay(500);
      driveMotors.setSpeeds(0,0);
      delay(500);

      endTicksLeft = lwEnc.read();
      endTicksRight = rwEnc.read();
      
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("MOTOR TEST");
      display.setCursor(0,15);
      display.println("Left Encoder");      
      display.setCursor(100,15);
      display.println(endTicksLeft);
      display.setCursor(0,30);
      display.println("Right Encoder");
      display.setCursor(100,30); 
      display.println(endTicksRight);
      display.display(); 

      delay(1000);
            
      driveMotors.setSpeeds(-75,75);
      delay(500);
      driveMotors.setSpeeds(0,0);
      endTicksLeft = lwEnc.read();
      endTicksRight = rwEnc.read();
      
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("MOTOR TEST");
      display.setCursor(0,15);
      display.println("Left Encoder");      
      display.setCursor(100,15);
      display.println(endTicksLeft);
      display.setCursor(0,30);
      display.println("Right Encoder");
      display.setCursor(100,30); 
      display.println(endTicksRight);
      display.display(); 

      delay(1000);

      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("Hello, world!");
      display.setCursor(0,15);
      display.setTextColor(BLACK,WHITE);
      display.println("1. Motor test");
      display.setCursor(0,30);
      display.setTextColor(WHITE);
      display.println("2. Lidar test");
      display.display();  
    }
  }
}


