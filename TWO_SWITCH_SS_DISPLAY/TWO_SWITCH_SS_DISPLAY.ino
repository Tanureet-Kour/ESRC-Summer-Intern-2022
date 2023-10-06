/* TO INCREMENT AND DECREMENT THE VALUE IN SEVEN SEGMENT  DISPLAY USING TWO SWITCHES 
PERFORMING THEIR RESPECTIVE OPERATIONS */
//SWITCH
const int   SWITCH_BLUE_INC = 14;
const int    SWITCH_RED_DEC = 17; 
//LED's
const int        BLUE_LED_INC = 15;
const int         RED_LED_DEC = 16;
//SWITCH MODE (HIGH/LOW)
int mode_INC ;
int mode_DEC ;
//SEVEN SEGMENT DISPLAY
const int ss_dp = 9;
const int ss_a  = 20;
const int ss_b  = 21;
const int ss_c  = 10;
const int ss_d  = 11;
const int ss_e  = 12;
const int ss_f  = 19;
const int ss_g  = 18;

void setup()
{
  pinMode( SWITCH_BLUE_INC , INPUT_PULLUP);
  pinMode( SWITCH_RED_DEC  , INPUT_PULLUP);
  
  pinMode( BLUE_LED_INC , OUTPUT);
  pinMode(  RED_LED_DEC , OUTPUT);

  pinMode( ss_dp , OUTPUT);
  pinMode( ss_a , OUTPUT);
  pinMode( ss_b , OUTPUT);
  pinMode( ss_c , OUTPUT);
  pinMode( ss_d , OUTPUT);
  pinMode( ss_e , OUTPUT);
  pinMode( ss_f , OUTPUT);
  pinMode( ss_g , OUTPUT);
}
int n = 0;
int count_inc = 0;
int count_dec = 0;
void loop()
{
  display_in_ss(n);


//mode_INC BLUE_LED_INC
  mode_INC = digitalRead(SWITCH_BLUE_INC);
  if(mode_INC == HIGH)
    digitalWrite( BLUE_LED_INC , LOW);
  else
    digitalWrite( BLUE_LED_INC , HIGH);
    count_inc++ ;

//mode_DEC RED_LED_DEC 
  mode_DEC = digitalRead(SWITCH_RED_DEC);
  if(mode_DEC == HIGH)
    digitalWrite( RED_LED_DEC, LOW);
  else
    digitalWrite( RED_LED_DEC, HIGH);
    count_dec-- ;
}
//////


void display_in_ss(unsigned int n);
{ //error checking
  if(n>9)
    {digitalWrite( ss_dp , HIGH);
    return;}
  //clear the display
  digitalWrite( ss_dp , LOW);
  digitalWrite( ss_a , LOW);
  digitalWrite( ss_b , LOW);
  digitalWrite( ss_c , LOW);
  digitalWrite( ss_d , LOW);
  digitalWrite( ss_e , LOW);
  digitalWrite( ss_f , LOW);
  digitalWrite( ss_g , LOW);

  switch(n)
  {
    case 0: 
            digitalWrite( ss_a , HIGH);//0
            digitalWrite( ss_b , HIGH);
            digitalWrite( ss_c , HIGH);
            digitalWrite( ss_d , HIGH);
            digitalWrite( ss_e , HIGH);
            digitalWrite( ss_f , HIGH);
            break;
    case 1: 
            digitalWrite( ss_b , HIGH);//1
            digitalWrite( ss_c , HIGH);
            break;
    case 2: 
            digitalWrite( ss_a , HIGH);//2
            digitalWrite( ss_b , HIGH);
            digitalWrite( ss_d , HIGH);
            digitalWrite( ss_e , HIGH);
            digitalWrite( ss_g , HIGH);            
            break;
    case 3: digitalWrite( ss_a , HIGH);//3
            digitalWrite( ss_b , HIGH);
            digitalWrite( ss_c , HIGH);
            digitalWrite( ss_d , HIGH);
            digitalWrite( ss_g , HIGH);            
            break;

    case 4: digitalWrite( ss_b , HIGH);//4
            digitalWrite( ss_c , HIGH);
            digitalWrite( ss_f , HIGH);
            digitalWrite( ss_g , HIGH);            
            break;

    case 5: digitalWrite( ss_a , HIGH);//5
            digitalWrite( ss_c , HIGH);
            digitalWrite( ss_d , HIGH);
            digitalWrite( ss_f , HIGH);
            digitalWrite( ss_g , HIGH);            
            break;

    case 6: digitalWrite( ss_a , HIGH);//6
            digitalWrite( ss_c , HIGH);
            digitalWrite( ss_d , HIGH);
            digitalWrite( ss_e , HIGH);
            digitalWrite( ss_f , HIGH);
            digitalWrite( ss_g , HIGH);            
            break;

    case 7: digitalWrite( ss_a , HIGH);//7
            digitalWrite( ss_b , HIGH);
            digitalWrite( ss_c , HIGH);
            break;

    case 8: digitalWrite( ss_a , HIGH);//8
            digitalWrite( ss_b , HIGH);
            digitalWrite( ss_c , HIGH);
            digitalWrite( ss_d , HIGH);
            digitalWrite( ss_e , HIGH);
            digitalWrite( ss_f , HIGH);
            digitalWrite( ss_g , HIGH);            
            break;
    case 9: digitalWrite( ss_a , HIGH);//9
            digitalWrite( ss_b , HIGH);
            digitalWrite( ss_c , HIGH);
            digitalWrite( ss_d , HIGH);
            digitalWrite( ss_f , HIGH);
            digitalWrite( ss_g , HIGH);            
            break;

        
  }
}
