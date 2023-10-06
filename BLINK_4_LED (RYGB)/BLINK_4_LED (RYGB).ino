/*TEAM NAME   - CYBORG
  TEAM NUMBER - 21
  TEAM LEADER -  ABHISHEK CHOUDHARY
  
2 Write a program to show moving light effect (walking one's effect) on 4 LED's connected to PicoBoard's GP pin number 10,11,12 and 13 with 
  RED , YELLOW, GREEN, WHITE/BLUE */

#define RED_LED 10 //GP
#define YELLOW_LED 11
#define GREEN_LED 12
#define BLUE_LED 13

void setup() {
 pinMode (RED_LED , OUTPUT);
 pinMode (YELLOW_LED , OUTPUT);
 pinMode (GREEN_LED , OUTPUT);
 pinMode (BLUE_LED , OUTPUT);


}

void loop() {

digitalWrite(RED_LED , HIGH);
delay(100);
digitalWrite(RED_LED , LOW);
delay(100);

digitalWrite(YELLOW_LED , HIGH);
delay(100);
digitalWrite(YELLOW_LED , LOW);
delay(100);

digitalWrite(GREEN_LED , HIGH);
delay(100);
digitalWrite(GREEN_LED , LOW);
delay(100);

digitalWrite(BLUE_LED , HIGH);
delay(100);
digitalWrite(BLUE_LED , LOW);
delay(100);
}
