#include <Adafruit_SSD1306.h>

#define LED_RED     22
#define LED_GREEN   23

#define BUTTON1     21
#define BUTTON2     22

#define OLED_MOSI   24
#define OLED_CLK    10
#define OLED_DC     11
#define OLED_CS     12
#define OLED_RESET  25

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  //pinMode(BUTTON1, INPUT);
  //pinMode(BUTTON2, INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)

  digitalWrite(LED_GREEN, HIGH);
  
  digitalWrite(LED_RED, HIGH);
  delay(500);
  digitalWrite(LED_RED, LOW);
  delay(500);
  digitalWrite(LED_RED, HIGH);
  delay(500);
  digitalWrite(LED_RED, LOW);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello, world!");
  display.setCursor(0,15);
  display.println("1. Motor test");
  display.setCursor(0,30);
  display.println("2. Lidar test");
  display.display();

  

}

void loop() {
  if (digitalRead(BUTTON1) == HIGH) {
    digitalWrite(LED_RED, HIGH);
    delay(300);
    digitalWrite(LED_RED, LOW);
  }
}


