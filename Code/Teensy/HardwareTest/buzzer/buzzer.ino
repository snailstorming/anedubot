
#define BUZZER_RED_LED  22

void setup() {
  //TEST BUZZER

  tone(BUZZER_RED_LED,2637,100);
  delay(150);
  tone(BUZZER_RED_LED,2637,100);
  delay(300);
  tone(BUZZER_RED_LED,2637,100);
  delay(300);
  tone(BUZZER_RED_LED,2093,100);
  delay(100);
  tone(BUZZER_RED_LED,2637,100);
  delay(300);
  tone(BUZZER_RED_LED,3136,100);
  delay(550);
  tone(BUZZER_RED_LED,1568,100);
  delay(575);
  //END TEST BUZZER

}

void loop() {
  // put your main code here, to run repeatedly:

}
