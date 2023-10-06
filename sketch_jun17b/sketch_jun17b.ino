// 3. Write a program to display APPLE on seven segment display

#define a 16 //GP
#define b 17
#define c 15
#define d 14
#define e 13
#define f 18
#define g 19

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {

//LETTER A
digitalWrite(a , HIGH);
digitalWrite(b , HIGH);
digitalWrite(c , HIGH);
digitalWrite(e , HIGH);
digitalWrite(f , HIGH);
digitalWrite(g , HIGH);

digitalWrite(d , LOW);
delay(2000);

digitalWrite(a , LOW);
digitalWrite(b , LOW);
digitalWrite(c , LOW);
digitalWrite(d , LOW);
digitalWrite(e , LOW);
digitalWrite(f , LOW);
digitalWrite(g , LOW);
delay(400);

//LETTER P
digitalWrite(a , HIGH);
digitalWrite(b , HIGH);
digitalWrite(g , HIGH);
digitalWrite(f , HIGH);
digitalWrite(e , HIGH);

digitalWrite(c , LOW);
digitalWrite(d , LOW);

delay(2000);

digitalWrite(a , LOW);
digitalWrite(b , LOW);
digitalWrite(c , LOW);
digitalWrite(d , LOW);
digitalWrite(e , LOW);
digitalWrite(f , LOW);
digitalWrite(g , LOW);
delay(400);

//LETTER P
digitalWrite(a , HIGH);
digitalWrite(b , HIGH);
digitalWrite(g , HIGH);
digitalWrite(f , HIGH);
digitalWrite(e , HIGH);

digitalWrite(c , LOW);
digitalWrite(d , LOW);

delay(2000);

digitalWrite(a , LOW);
digitalWrite(b , LOW);
digitalWrite(c , LOW);
digitalWrite(d , LOW);
digitalWrite(e , LOW);
digitalWrite(f , LOW);
digitalWrite(g , LOW);
delay(400);

//LETTER L
digitalWrite(f , HIGH);
digitalWrite(e , HIGH);
digitalWrite(d , HIGH);

digitalWrite(a , LOW );
digitalWrite(b , LOW);
digitalWrite(c , LOW);
digitalWrite(g , LOW);

delay(2000);

digitalWrite(a , LOW);
digitalWrite(b , LOW);
digitalWrite(c , LOW);
digitalWrite(d , LOW);
digitalWrite(e , LOW);
digitalWrite(f , LOW);
digitalWrite(g , LOW);
delay(400);

//LETTER E
digitalWrite(a , HIGH);
digitalWrite(f , HIGH);
digitalWrite(g , HIGH);
digitalWrite(e , HIGH);
digitalWrite(d , HIGH);

digitalWrite(b , LOW);
digitalWrite(c , LOW);
delay(2000);

digitalWrite(a , LOW);
digitalWrite(b , LOW);
digitalWrite(c , LOW);
digitalWrite(d , LOW);
digitalWrite(e , LOW);
digitalWrite(f , LOW);
digitalWrite(g , LOW);
delay(400);

delay(1000);
}
