#define buzzer 13

void setup()
{
  pinMode( buzzer , OUTPUT);
}
voidloop()
{
digitalWrite( buzzer , HIGH );
delay(1000);
digitalWrite( buzzer , LOW );
delay(1000);
}