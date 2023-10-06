#define RED_LED_PIN A0
#define GREEN_LED_PIN A1
#define BLUE_LED_PIN A2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int r=0,g=0,b=0;
  for(r=0;r<=255;r+=30){
    analogWrite(RED_LED_PIN, r);
    for(g=0;g<=255;g+=30){
      analogWrite(GREEN_LED_PIN, g);
      for(b=0;b<=255;b+=30){
        analogWrite(BLUE_LED_PIN, b);
        delay(200);
      }
    }
  }
}
