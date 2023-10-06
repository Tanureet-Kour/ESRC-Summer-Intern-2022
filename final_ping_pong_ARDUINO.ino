//FINAL END TERM PROJECT (CLASSIC PING-PONG GAME)

//initialisations of GPIO pins

// 2 SEVEN SEGMENT DISPLAYS
/*SEVEN SEGMENT DISPLAY 1 
(to display current match score of player_1)*/
#define A1 18
#define B1 19
#define C1 13
#define D1 14
#define E1 15
#define F1 17
#define G1 16
/*SEVEN SEGMENT DISPLAY 2 
(to display current match score of player_2)*/
#define A2 22
#define B2 28
#define C2 10
#define D2 11
#define E2 12
#define F2 21
#define G2 20


/* 2 POTENTIOMETERS 
( to control the up and down movement of the respective player's paddle)*/
//PLAYER_1_POT_LEFT
const int  left_potPin_player_1 = A0;    //GP 26
//PLAYER_2_POT_RIGHT
const int right_potPin_player_2 = A1;    //GP 27


/* 1 BUZZER
(to have different sound effectsin the game)*/
#define buzzer_pin 9


// 3 SWITCHES 

/*SWITCH_BUTTON_1 
(for the purpose of RUN button)
//const int switch_upper = RUN  (physical pin 30)*/

/*SWITCH_BUTTON_2 
(to perform game start and restart operations)*/
const int switch_middle = 8;

/*SWITCH_BUTTON_2
(to control the desired speed of the game)*/
const int  switch_lower = 7;

/////////////////////////////////////////////////////////////////
int  pot_left_player_1 ;
int pot_right_player_2 ;

void setup() {
  Serial.begin(9600);  
  // SEVEN SEGMENT DISPLAY 1
  pinMode( A1 , OUTPUT );
  pinMode( B1 , OUTPUT );
  pinMode( C1 , OUTPUT );

  pinMode( D1 , OUTPUT );
  pinMode( E1 , OUTPUT );
  pinMode( F1 , OUTPUT );
  pinMode( G1 , OUTPUT );
  // SEVEN SEGMENT DISPLAY 2
  pinMode( A2 , OUTPUT );
  pinMode( B2 , OUTPUT );
  pinMode( C2 , OUTPUT );
  pinMode( D2 , OUTPUT );
  pinMode( E2 , OUTPUT );
  pinMode( F2 , OUTPUT );
  pinMode( G2 , OUTPUT );
  // 2*POTENTIOMETER
  pinMode(  left_potPin_player_1 , INPUT );
  pinMode( right_potPin_player_2 , INPUT );
  // BUZZER
  pinMode( buzzer_pin , OUTPUT );
  // 3*BUTTON_SWITCHES
  //pinMode(  switch_upper , INPUT ); RUN_BUTTON PP_30
  pinMode( switch_middle , INPUT );
  pinMode(  switch_lower , INPUT );
  
 }

void loop() {
  // 2*POTENTIOMETER VALUES
  pot_left_player_1 = analogRead( left_potPin_player_1);
  Serial.println( pot_left_player_1);
  pot_left_player_1 = analogRead(right_potPin_player_2);
  Serial.println(pot_right_player_2);  
}
