#define Red 4
#define Yellow 3
#define Green 2

void setup() {
  pinMode(Red, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);
  Serial.begin(9600);
  delay(400);
  Serial.println("r");
  Serial.println("y");
  Serial.println("g");
}
String command;
void loop() {
  if (Serial.available()) {
    command = Serial.readStringUntil('\n');
    command.trim();
    if (command.equals("r")) {
      digitalWrite(Red, HIGH);
      digitalWrite(Yellow, LOW);
      digitalWrite(Green, LOW);
    } else if (command.equals("y")) {
      digitalWrite(Yellow, HIGH);
      digitalWrite(Red, LOW);
      digitalWrite(Green, LOW);
    } else if (command.equals("g")) {
      digitalWrite(Green, HIGH);
      digitalWrite(Yellow, LOW);
      digitalWrite(Red, LOW);
    } else if (command.equals("a")) {
      digitalWrite(Yellow, HIGH);
      digitalWrite(Green, HIGH);
      digitalWrite(Red, HIGH);
      delay(1000);
      digitalWrite(Yellow, HIGH);
      digitalWrite(Green, HIGH);
      digitalWrite(Red, HIGH);
      delay(1000);
      digitalWrite(Yellow, HIGH);
      digitalWrite(Green, HIGH);
      digitalWrite(Red, HIGH);
      delay(1000);
    }

    Serial.println("command");
    Serial.println(command);
  }
}