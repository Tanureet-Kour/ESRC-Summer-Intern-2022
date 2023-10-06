void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode( 15 , OUTPUT );

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    char data = Serial.read();
    switch(data)
    {
      case '1' : digitalWrite ( 15 , HIGH ); break;
      case '0' : digitalWrite ( 15 , LOW)  ; break;
    }
    Serial.println(data);
  }
  delay(50);
  }
