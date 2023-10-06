#include "motor.h"

//#ifdef __cplusplus
// extern "C" {
// #endif
/////////////////////////////////////////////////////////////////////////
void motionForward(int speed)
{
  analogWrite( MOTOR_LEFT_A_PIN_NO, speed );
  pinMode(     MOTOR_LEFT_B_PIN_NO, OUTPUT);
  digitalWrite(MOTOR_LEFT_B_PIN_NO, LOW   );

  pinMode(     MOTOR_RIGHT_A_PIN_NO, OUTPUT);
  digitalWrite(MOTOR_RIGHT_A_PIN_NO, LOW   );
  analogWrite( MOTOR_RIGHT_B_PIN_NO, speed );

  digitalWrite(MOTOR_STANDBY_PIN_NO, MOTOR_DRIVER_ENABLE);
}
/////////////////////////////////////////////////////////////////////////
void motionReverse(int speed)
{
  pinMode(     MOTOR_LEFT_A_PIN_NO, OUTPUT);
  digitalWrite(MOTOR_LEFT_A_PIN_NO, LOW   );
  analogWrite( MOTOR_LEFT_B_PIN_NO, speed );

  analogWrite( MOTOR_RIGHT_A_PIN_NO, speed );
  pinMode(     MOTOR_RIGHT_B_PIN_NO, OUTPUT);
  digitalWrite(MOTOR_RIGHT_B_PIN_NO, LOW   );

  digitalWrite(MOTOR_STANDBY_PIN_NO, MOTOR_DRIVER_ENABLE);
}
/////////////////////////////////////////////////////////////////////////
void motionStop(void)
{
  pinMode(     MOTOR_RIGHT_A_PIN_NO, OUTPUT);
  digitalWrite(MOTOR_RIGHT_A_PIN_NO, LOW);

  pinMode(     MOTOR_RIGHT_B_PIN_NO, OUTPUT);
  digitalWrite(MOTOR_RIGHT_B_PIN_NO, LOW);

  pinMode(     MOTOR_LEFT_A_PIN_NO, OUTPUT);
  digitalWrite(MOTOR_LEFT_A_PIN_NO,  LOW);

  pinMode(     MOTOR_LEFT_B_PIN_NO, OUTPUT);
  digitalWrite(MOTOR_LEFT_B_PIN_NO,  LOW);

  digitalWrite(MOTOR_STANDBY_PIN_NO, MOTOR_DRIVER_STANDBY);
}
/////////////////////////////////////////////////////////////////////////
// #ifdef __cplusplus
// }
// #endif