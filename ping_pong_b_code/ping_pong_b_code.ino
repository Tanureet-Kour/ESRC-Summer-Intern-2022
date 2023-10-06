#define playerOne A1
#define playerTwo A0

#define playerOneSwitch 19
#define playerTwoSwitch 18

#define PLAYER1_PIN_A 9
#define PLAYER1_PIN_B 8
#define PLAYER1_PIN_F 17
#define PLAYER1_PIN_G 16

#define PLAYER1_PIN_E 15
#define PLAYER1_PIN_D 14
#define PLAYER1_PIN_C 13
#define PLAYER1_PIN_DP 

#define PLAYER2_PIN_A 22
#define PLAYER2_PIN_B 28
#define PLAYER2_PIN_F 21
#define PLAYER2_PIN_G 20

#define PLAYER2_PIN_E 12
#define PLAYER2_PIN_D 11
#define PLAYER2_PIN_C 10
#define PLAYER2_PIN_DP 

int playerOnePins[] = {PLAYER1_PIN_A, PLAYER1_PIN_B, PLAYER1_PIN_F, PLAYER1_PIN_G, PLAYER1_PIN_E, PLAYER1_PIN_D, PLAYER1_PIN_C, PLAYER1_PIN_DP};
// int playerTwoPins[] = {PLAYER2_PIN_A, PLAYER2_PIN_B, PLAYER2_PIN_F, PLAYER2_PIN_G, PLAYER2_PIN_E, PLAYER2_PIN_D, PLAYER2_PIN_C, PLAYER2_PIN_DP};

int Numbers[10][8] = {
// A, B, F, G, E, D, C, DP  
  {0, 0, 0, 1, 0, 0, 0, 0}, // 0
  {1, 0, 1, 1, 1, 1, 0, 1}, // 1
  {0, 0, 1, 0, 0, 0, 1, 1}, // 2
  {0, 0, 1, 0, 1, 0, 0, 0}, // 3
  {1, 0, 0, 0, 1, 1, 0, 1}, // 4 

// A, B, F, G, E, D, C, DP 
  {0, 1, 0, 0, 1, 0, 0, 0}, // 5 
  {0, 1, 0, 0, 0, 0, 0, 0}, // 6 
  {0, 0, 1, 1, 1, 1, 0, 1}, // 7 
  {0, 0, 0, 0, 0, 0, 0, 0}, // 8 
  {0, 0, 0, 0, 1, 0, 0, 0}  // 9
}; 


void setup() {
  Serial.begin(9600);
  pinMode(playerOneSwitch, INPUT_PULLUP);
  pinMode(playerTwoSwitch, INPUT_PULLUP);

  for(int i=0;i<8;i++) {
    pinMode(playerOnePins[i], OUTPUT);
  }

  // for(int i=0;i<8;i++) {
  //   pinMode(playerTwoPins[i], OUTPUT);
  // }
}

int player1, player2;
int player1Switch, player2Switch;
int counter=0;

void loop() {
  player1 = analogRead(playerOne);
  player2 = analogRead(playerTwo);

  player1Switch = digitalRead(playerOneSwitch);
  player2Switch = digitalRead(playerTwoSwitch);

  player1 = map(player1, 0, 1023, 0, 452);
  player2 = map(player2, 0, 1023, 0, 452);

  Serial.print(player1);
  Serial.print(",");
  Serial.print(player2);
  Serial.print(",");
  Serial.print(player1Switch);
  Serial.print(",");
  Serial.println(player2Switch);

  // Serial.println();
  // Serial.print("From Processing");
  // // string val = Serial.read();
  // Serial.print(Serial.read());

  for(int i=0;i<9;i++) {
    digitalWrite(playerOnePins[i], Numbers[2][i]);
  }
  // for(int i=0;i<9;i++) {
  //   digitalWrite(playerTwoPins[i], Numbers[counter][i]);
  // }
  // counter++;
  // delay(500);
}
