// source: https://github.com/pololu/vl53l0x-arduino/issues/1

#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;
VL53L0X sensor2;

int distance;
unsigned long StartTime;
int fps;

void setup()
{

  pinMode(17, OUTPUT);
  pinMode(16, OUTPUT);
  digitalWrite(17, LOW);
  digitalWrite(16, LOW);

  delay(500);
  Wire.begin();


  Serial.begin (9600);

  digitalWrite(17, HIGH);
  delay(150);
  Serial.println("00");
  sensor.init(true);

  Serial.println("01");
  delay(100);
  sensor.setAddress((uint8_t)22);
  Serial.println("02");

  digitalWrite(16, HIGH);
    delay(150);
  sensor2.init(true);
  Serial.println("03");
  delay(100);
  sensor2.setAddress((uint8_t)25);
  Serial.println("04");

  Serial.println("addresses set");

  Serial.println ("I2C scanner. Scanning ...");
  byte count = 0;


  for (byte i = 1; i < 120; i++)
  {

    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
    {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
      delay (1);  // maybe unneeded?
    } // end of good response
  } // end of for loop
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");

//HIGH_SPEED
  sensor.setMeasurementTimingBudget(20000);
  sensor2.setMeasurementTimingBudget(20000);

  delay(3000);
  
  StartTime = millis();
  fps = 0;
  
}

void loop()
{

   if ( millis() - StartTime >= 1000){
   Serial.print("fps : ");
   Serial.println(fps);
   fps = 0;
   StartTime = millis();
 }
 else {
  fps = fps + 1;
 }
Serial.print(sensor.readRangeSingleMillimeters());
Serial.print(" : ");
Serial.println(sensor2.readRangeSingleMillimeters());

}
