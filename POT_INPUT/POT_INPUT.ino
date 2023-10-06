//GET INPUT FROM POT 

const int analogPin = A0;
int value;
void setup() {
  // put your setup code here, to run once:
  pinMode(analogPin , INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:    
  value = analogRead(analogPin);
  Serial.println(value);
  delay(100);
}
