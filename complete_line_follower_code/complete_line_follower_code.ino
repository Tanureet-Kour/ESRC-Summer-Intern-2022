#define IR_left 13
#define IR_right 12


// #define Motor_driver_enable 1
// #define Motor_driver_standby 0

#define Motor_left_A_pin 16
#define Motor_left_B_pin 17
// #define Motor_stanby_pin 18
#define Motor_right_A_pin 19
#define Motor_right_B_pin 20


void setup() 
{
  // Serial.begin(9600);
  // IR sensors 
  pinMode(IR_left, INPUT);
  pinMode(IR_right, INPUT);
  
  
  // left motor
  pinMode(Motor_left_A_pin, OUTPUT);
  pinMode(Motor_left_B_pin, OUTPUT);

  pinMode(Motor_stanby_pin, OUTPUT);
 
  // right motor
  pinMode(Motor_right_A_pin, OUTPUT);
  pinMode(Motor_right_B_pin, OUTPUT);
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void loop() 
{
  int l = digitalRead(IR_left);
  int r = digitalRead(IR_right);

  if(l== 1 && r==1)
  {
    motion_Forward(22);
  }

  if(l==0 && r==1)
  {
    motion_Right(25);
  }

  if(l==1 && r==0)
  {
    motion_Left(25);
  }

  if(l==0 && r==0)
  {
    motion_Stop();
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////
void motion_Forward (int speed)
{
  analogWrite(Motor_left_A_pin, speed);
  digitalWrite(Motor_left_B_pin, LOW);

  digitalWrite(Motor_right_A_pin, LOW);
  analogWrite(Motor_right_B_pin, speed);

  // digitalWrite(Motor_stanby_pin, Motor_driver_enable );
  
}

void motion_Reverse (int speed)
{
  digitalWrite(Motor_left_A_pin, LOW);
  analogWrite(Motor_left_B_pin, speed);

  analogWrite(Motor_right_A_pin, speed);
  digitalWrite(Motor_right_B_pin, LOW);

  // digitalWrite(Motor_stanby_pin, Motor_driver_enable );
  
}

void motion_Stop (void)
{
  digitalWrite(Motor_left_A_pin, LOW);
  digitalWrite(Motor_left_B_pin, LOW);

  digitalWrite(Motor_right_A_pin, LOW);
  digitalWrite(Motor_right_B_pin, LOW);

  // digitalWrite(Motor_stanby_pin, Motor_driver_enable );
  
}

void motion_Left (int speed)
{
  analogWrite(Motor_left_A_pin, LOW);
  digitalWrite(Motor_left_B_pin, LOW);

  digitalWrite(Motor_right_A_pin, LOW);
  analogWrite(Motor_right_B_pin, speed);

  // digitalWrite(Motor_stanby_pin, Motor_driver_enable );
  
}

void motion_Right (int speed)
{
  analogWrite(Motor_left_A_pin, speed);
  digitalWrite(Motor_left_B_pin, LOW);

  digitalWrite(Motor_right_A_pin, LOW);
  analogWrite(Motor_right_B_pin, LOW);

  // digitalWrite(Motor_stanby_pin, Motor_driver_enable );
  
}
