#define MOTOR_LEFT_A_PIN_NO  16
#define MOTOR_LEFT_B_PIN_NO  17
#define MOTOR_STANDBY_PIN_NO 18
#define MOTOR_RIGHT_A_PIN_NO 19
#define MOTOR_RIGHT_B_PIN_NO 20

#define IR_LEFT_PIN_NO  13
#define IR_RIGHT_PIN_NO 12

#define IR_ON_PIN_NO 10

#define BATTERY_VOLTAGE_CHECK_PIN_NO A2
#define ANALOG_REFERENCE_VOLTAGE     3.3
#define ANALOG_READ_RESOLUTION       12
#define R7_OHM_POSITIVE              10000.0
#define R8_OHM_GROUND                5100.0
#define BATTERY_LOW_VOLTAGE_CUTOFF   7.0

#define ANALOG_WRITE_RESOLUTION 16
#define MOTOR_DRIVER_ENABLE     1
#define MOTOR_DRIVER_STANDBY    0\

int gati = 25;

const float voltageDividerRatio = (R7_OHM_POSITIVE + R8_OHM_GROUND) / R8_OHM_GROUND;
const float adcCountToVolt = ANALOG_REFERENCE_VOLTAGE / (pow(2, ANALOG_READ_RESOLUTION) - 1) * voltageDividerRatio; 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
    
    pinMode(MOTOR_LEFT_A_PIN_NO, OUTPUT);
    pinMode(MOTOR_LEFT_B_PIN_NO, OUTPUT);

    pinMode(MOTOR_STANDBY_PIN_NO, OUTPUT);

    pinMode(MOTOR_RIGHT_A_PIN_NO, OUTPUT);
    pinMode(MOTOR_RIGHT_B_PIN_NO, OUTPUT);
    
    pinMode(IR_LEFT_PIN_NO, INPUT);
    pinMode(IR_RIGHT_PIN_NO, INPUT);
    
    pinMode(IR_ON_PIN_NO, INPUT);
    
    pinMode(BATTERY_VOLTAGE_CHECK_PIN_NO, INPUT); 

    analogReadResolution(ANALOG_READ_RESOLUTION);

    // analogWruteResolution(ANALOG_WRITE_RESOLUTION);
    analogWriteResolution(8);

    // blink_n_beep(3, 500);
    // BT.println("\r\n========== RESET ==========");

    // motionForward(1048576);
    // delay(1000);
    // motionStop();
    // delay(2000);

    // motionReverse(0);
    // delay(1000);
    // motionStop();
    // delay(2000);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// int i=0;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
    // Bt.print("\r\n");
    // Bt.print(i);
    batteryVoltageCheck();

    // delay(100);
    // i++;
    if(digitalRead(IR_LEFT_PIN_NO) == 1 && digitalRead(IR_RIGHT_PIN_NO) == 1){
      motionForward(gati);
    }
    else if(digitalRead(IR_LEFT_PIN_NO)==1 && digitalRead(IR_RIGHT_PIN_NO) == 0){
      turnRight(gati);
    }
    else if(digitalRead(IR_LEFT_PIN_NO)==0 && digitalRead(IR_RIGHT_PIN_NO) == 1){
      turnLeft(gati);
    }
    else if(digitalRead(IR_LEFT_PIN_NO)==0 && digitalRead(IR_RIGHT_PIN_NO) == 0){
      motionStop();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void turnRight(int speed){
    analogWrite( MOTOR_LEFT_A_PIN_NO,  speed);
    // pinMode(     MOTOR_LEFT_B_PIN_NO,  OUTPUT);
    digitalWrite(MOTOR_LEFT_B_PIN_NO,  LOW);
    
    // pinMode(     MOTOR_RIGHT_A_PIN_NO, OUTPUT);
    digitalWrite(MOTOR_RIGHT_A_PIN_NO, LOW);
    analogWrite( MOTOR_RIGHT_B_PIN_NO, LOW);

    digitalWrite(MOTOR_STANDBY_PIN_NO, MOTOR_DRIVER_ENABLE);
}

void turnLeft(int speed){
  analogWrite( MOTOR_LEFT_A_PIN_NO,  LOW);
    // pinMode(     MOTOR_LEFT_B_PIN_NO,  OUTPUT);
    digitalWrite(MOTOR_LEFT_B_PIN_NO,  LOW);
    
    // pinMode(     MOTOR_RIGHT_A_PIN_NO, OUTPUT);
    digitalWrite(MOTOR_RIGHT_A_PIN_NO, LOW);
    analogWrite( MOTOR_RIGHT_B_PIN_NO, speed);

    digitalWrite(MOTOR_STANDBY_PIN_NO, MOTOR_DRIVER_ENABLE);
}

void motionForward(int speed) {
    analogWrite( MOTOR_LEFT_A_PIN_NO,  speed);
    // pinMode(     MOTOR_LEFT_B_PIN_NO,  OUTPUT);
    digitalWrite(MOTOR_LEFT_B_PIN_NO,  LOW);
    
    // pinMode(     MOTOR_RIGHT_A_PIN_NO, OUTPUT);
    digitalWrite(MOTOR_RIGHT_A_PIN_NO, LOW);
    analogWrite( MOTOR_RIGHT_B_PIN_NO, speed);

    digitalWrite(MOTOR_STANDBY_PIN_NO, MOTOR_DRIVER_ENABLE);    //??
}
/////////////////////////////////////
void motionReverse(int speed) {
    // pinMode(     MOTOR_LEFT_A_PIN_NO, OUTPUT);
    digitalWrite(MOTOR_LEFT_A_PIN_NO, LOW);
    analogWrite( MOTOR_LEFT_B_PIN_NO, speed);

    analogWrite( MOTOR_RIGHT_A_PIN_NO, speed);
    // pinMode(     MOTOR_RIGHT_B_PIN_NO, OUTPUT);
    digitalWrite(MOTOR_RIGHT_B_PIN_NO, LOW);
    
    digitalWrite(MOTOR_STANDBY_PIN_NO, MOTOR_DRIVER_ENABLE);
}
/////////////////////////////////////
void motionStop(void) {
    // pinMode(     MOTOR_RIGHT_A_PIN_NO, OUTPUT);
    digitalWrite(MOTOR_RIGHT_A_PIN_NO, LOW);
    pinMode(     MOTOR_LEFT_B_PIN_NO, OUTPUT);
    digitalWrite(MOTOR_LEFT_B_PIN_NO, LOW);

    // pinMode(     MOTOR_LEFT_A_PIN_NO, OUTPUT);
    digitalWrite(MOTOR_LEFT_A_PIN_NO, LOW);
    pinMode(     MOTOR_LEFT_B_PIN_NO, OUTPUT);
    digitalWrite(MOTOR_LEFT_B_PIN_NO, LOW);

    digitalWrite(MOTOR_STANDBY_PIN_NO, MOTOR_DRIVER_STANDBY);
}
/////////////////////////////////////
float batteryVoltageCheck(void) {
    int adcCount = analogRead(BATTERY_VOLTAGE_CHECK_PIN_NO);
    float voltageOfBattery;

    voltageOfBattery = adcCount * adcCountToVolt;

    // BT.print("\r\n adcCount = ");
    // // BT.print(adcCount);
    // BT.print("\r\n voltageDividerRatio = ");
    // BT.print(voltageDividerRatio);
    // BT.print("\r\n adcCountToVolt = ");
    // BT.print(adcCountToVolt);

    // BT.print("\r\n Battery Voltage = ");
    // BT.print(voltageOfBattery);

    if(voltageOfBattery < BATTERY_LOW_VOLTAGE_CUTOFF) {
        digitalWrite(MOTOR_STANDBY_PIN_NO, MOTOR_DRIVER_STANDBY);
        digitalWrite(IR_ON_PIN_NO, LOW);

        // BT.print("\r\n adcCount = ");
        // // BT.print(adcCount);
        // BT.print("\r\n voltageDividerRatio = ");
        // BT.print(voltageDividerRatio);
        // BT.print("\r\n adcCountToVolt = ");
        // BT.print(adcCountToVolt);

        // BT.print("\r\n Battery Voltage = ");
        // BT.print(voltageOfBattery);

        // hang();
    }
    return voltageOfBattery;
}

// void blink(int n, int timePeriod) {
//     while(n > 0) {
//         digitalWrite(LED_BUILTIN,        HIGH);
//         digitalWrite(LED_SUCCESS_PIN_NO, HIGH);
//         delay(timePeriod/2);

//         digitalWrite(LED_BUILTIN,        LOW);
//         digitalWrite(LED_SUCCESS_PIN_NO, LOW);
//         delay(timePeriod/2);

//         n--;
//     }
// }

// void beep(int n, int timePeriod) {
//     while(n > 0) {
//         digitalWrite(BUZZER_PIN_NO, HIGH);
//         delay(timePeriod/2);

//         digitalWrite(BUZZER_PIN_NO, LOW);
//         delay(timePeriod/2);

//         n--;
//     }
// }

// void blink_n_beep(int n, int timePeriod) {
//     while(n > 0) {
//         digitalWrite(LED_BUILTIN,        HIGH);
//         digitalWrite(LED_SUCCESS_PIN_NO, HIGH);
//         digitalWrite(BUZZER_PIN_NO,      HIGH);
//         delay(timePeriod/2);

//         digitalWrite(LED_BUILTIN,        LOW);
//         digitalWrite(LED_SUCCESS_PIN_NO, LOW);
//         digitalWrite(BUZZER_PIN_NO,      LOW);
//         delay(timePeriod/2);

//         n--;
//     }
// }

// void hang(void) {
//     int t = 0;
//     BT.println("\r\n############ HANG ############");

//     digitalWrite(BUZZER_PIN_NO, HIGH);
//     delay(2000);
//     digitalWrite(BUZZER_PIN_NO, LOW);

//     while(1) {
//         digitalWrite(LED_BUILTIN,        HIGH);
//         digitalWrite(LED_SUCCESS_PIN_NO, LOW);
//         delay(200);

//         digitalWrite(LED_BUILTIN,        LOW);
//         digitalWrite(LED_SUCCESS_PIN_NO, HIGH);
//         delay(200);

//         if(t%100)
//             BT.print("H");
//         t++;
//     }
// }
