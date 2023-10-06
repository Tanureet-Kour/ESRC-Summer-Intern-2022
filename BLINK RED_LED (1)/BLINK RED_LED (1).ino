/* TEAM NAME  - PIRATES
  TEAM NUMBER - 37
  TEAM LEADER -  Jasmeet Kaur
  
 1. Write a program to blink RED LED connected to PicoBoard GPIO PIn Number : 16 */

#define RED_LED 0 //GP 16
void setup() {
  pinMode( RED_LED , OUTPUT);
}

void loop() {

  digitalWrite(RED_LED , HIGH);
  delay(1000);
  digitalWrite(RED_LED , LOW);
  delay(1000);

}
