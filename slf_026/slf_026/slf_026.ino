// All Debug messages will be sent to BOTH: USB and Bluetooth

#include "hal.h"
#include "debug.h"
#include "motor.h"
#include "QTRSensors.h"
#include "battery.h"
#include "utils.h"
#include "ui.h"
#include "pid.h"



/////////////////////////////////////////////////////////////////////////
unsigned int result[8];
unsigned char sensorByte;
    
/////////////////////////////////////////////////////////////////////////

void setup()
{
    init_GPIO();
//    batteryVoltageCheck(1); // Check
    
    DUMP_L1_a("\r Press the TOP Button to continue:"); // NOTE THE  USE OF \r ONLY (not \n)
    waitForSwitchPress(SWITCH_TOP, PRINT);
    ////DUMP_L1_a("[2J"); // CLEAR SCREEN COMMAND
    //////performCalibration(NO_PRINT); // leave it commented: No calibration for this version of code

//                        unsigned int test=1;
//                        int bitCount=0;
//                        DUMP_L1_a("\r\n Max_Int is :");
//                        while(test)
//                        {
//                          DUMP_L1_ab("\r\n test= ", test);
//                          test = test << 1;
//                          bitCount++;
//                          delay(50);
//                        }
//                        DUMP_L1_ab("\r\n The size of \"unsigned int\" is = bitCount= ", bitCount);
//                        while(1);
    
    delay(100);
//    batteryVoltageCheck(1); // Check
    delay(100);
    DUMP_L1_ab("\r\n NOTE 1:  FOR MOTOR PWM:    ANALOG_WRITE_RESOLUTION= ", ANALOG_WRITE_RESOLUTION);
    DUMP_L1_a ("\r\n NOTE 2:  Voltage BOOSTER output = 8.6V");
    DUMP_L1_a ("\r\n          If you change it, then PID constants (Kp, Ki, Kd) needs to be changed");
    DUMP_L1_a ("\r\n");
    DUMP_L1_a ("\r\n                               ||");
    DUMP_L1_a ("\r\n Place the robot on a Line F--ollo--wer ARENA (White paper with a Black line-strip path)");
    DUMP_L1_a ("\r\n                               ||");
    DUMP_L1_a ("\r\n                               ||");

    DUMP_L1_a ("\r\n Press the MIDDEL Button to RUN the robot using PID algo:");
    waitForSwitchPress(SWITCH_MIDDLE, NO_PRINT);    

    int i=1;
    int lineNumber;
    
    
    // TESTing of functions  1 and 2
    //while(1)
    {

        // TESTing of function 1 : The Binary version
        //DUMP_L1_ab("\r\n i= ", i);
        //sensorByte =getSensorArrayValuesBinary( NO_PRINT);
        //lineNumber = readLineBINARY(sensorByte, NO_PRINT);
        //DUMP_L1_ab(" lineNumber=", lineNumber);
        //drawLine(lineNumber);
        //delay(600);
        //i++;

        // TESTing of function 2 : The time consuming version 
        //DUMP_L1_ab("\r\n i= ", i);
        //getSensorArrayValues(&result[0], NO_PRINT);  // read un-calibrated sensor data
        //lineNumber = readLine(&result[0], NO_PRINT); // determine robot's current position w.r.t Black line
        //DUMP_L1_ab(" lineNumber=", lineNumber);
        //drawLine(lineNumber);
        //delay(600);
        //i++;

        
    }
}
/////////////////////////////////////////////////////////////////////////

#define DRY_RUN 0

#define STANDARD_LEFT_MOTOR_SPEED   30
#define STANDARD_RIGHT_MOTOR_SPEED  30

#define OUTPUT_PID_MAX              15
#define OUTPUT_PID_MIN             -10

#define NUMBER_OF_ITERATIONS_PER_SECOND    50L
#define STOP_SIGN_MULTI_CHECK_SAMPLE_COUNT 1000

const long LOOP_TIME_IN_MICRO_SECONDS = (1000000L / NUMBER_OF_ITERATIONS_PER_SECOND );

      int reallyOnBlackBlock =0; // Re-assurance count
      int lineNumber;

      int error;
      int previousError;

const int Kp =   50; // PID constants
const int Kd =   10;
const int Ki =   10;

      int pTerm;
      int iTerm = 0; // Initialize
      int dTerm;
      int outputPID;

      int leftMotorSpeed, rightMotorSpeed; // Motor Speeds

      unsigned int lcv=0; // loop count variable
      unsigned long time1;
      unsigned long timeSpaceRemaining; // How much more room we have!

      char str[120];

void loop()
{

    // STEP: Note the current time in micro-seconds
    time1 = micros();

    // STEP: Get current position data   
    sensorByte =getSensorArrayValuesBinary( NO_PRINT);
    lineNumber = readLineBINARY(sensorByte, NO_PRINT);

    // STEP: Check if STOP BLOCK is detected :
    if(lineNumber == 2000)
    {
        reallyOnBlackBlock++;
        if(reallyOnBlackBlock >= STOP_SIGN_MULTI_CHECK_SAMPLE_COUNT)
        {
            motionStop(); // Stop Motors
            digitalWrite(LED_SUCCESS_PIN_NO, HIGH);
            
            delay(100);
            DUMP_L1_a("\r\n  BLACK BLOCK DETECTED   STOP \r\n");
            drawLine(lineNumber);

            DUMP_L1_a ("\r\n Press the BOTTOM Button to IGNORE (or RESET button to Start Over)");
            beep(5, 400); // 
            
            waitForSwitchPress(SWITCH_BOTTOM, NO_PRINT);  
            iTerm = 0;
            //while(1);  // FINALLY HANG
        }

        // Wait for some time and then return
        while( (micros() - time1) <  LOOP_TIME_IN_MICRO_SECONDS)
            ;
        return; // The loop() function returns for now, to be called again; further code is NOT executed    
    }
    reallyOnBlackBlock=0;

    // STEP:  In Maths, number-line have negative on left, positive on right
    error = lineNumber - 650; ///  lineNumber - (1300/2);
    //error=0; // For Testing Motors at SET Max Speed: Ignores PID Algo (as Error=0)
    

    // STEP: Calculate Proportional Term
       pTerm = error * Kp;

    // STEP: Calculate Integral Term
       iTerm = iTerm + (error * Ki);

    // STEP: Calculate Derivative Term
       dTerm = (error -  previousError) * Kd;


    // STEP: Calculate P + I + D
    outputPID = pTerm + iTerm + dTerm;

    outputPID = outputPID / 256; // Convert from 16-bit to 8-bit

         if (outputPID > OUTPUT_PID_MAX)  outputPID = OUTPUT_PID_MAX;
    else if (outputPID < OUTPUT_PID_MIN)  outputPID = OUTPUT_PID_MIN;

    
    
    leftMotorSpeed   = STANDARD_LEFT_MOTOR_SPEED  - outputPID;
    rightMotorSpeed  = STANDARD_RIGHT_MOTOR_SPEED + outputPID;
    
    if( DRY_RUN ==0) // If its an actural run then give commands to motor
        { 
            moveMotors( leftMotorSpeed, rightMotorSpeed, NO_PRINT);    

            //else //
//            if(lcv%100==0)
//            {
//            sprintf(str,"\r\n%4d E=%5d P=%6d I=%7d D=%6d O=%5d\t\tL=%3d R=%3d", 
//                            lcv, error, pTerm, iTerm, dTerm, outputPID, leftMotorSpeed, rightMotorSpeed);
//            DUMP_L1_a(str);
//            }
        }

    previousError = error;
    
    // The above loop must always take a unit time to execute
    // For integration dt is unit time
    // We want Robot to correct its position 50 times per second
    // 1sec/50 counts = 1000ms/50 counts = 20ms/count or 20,000 uS/ count
    // 


//    timeSpaceRemaining=0;
//    while( (micros() - time) < LOOP_TIME_IN_MICRO_SECONDS ) // Consume full unit loop time [Pass/kill time, if extra]
//    {    
//        delayMicroseconds(1);
//        timeSpaceRemaining++;
//    }
//    if(timeSpaceRemaining < 10)
//    {
//
//       DUMP_L1_ab(" T= ", timeSpaceRemaining); 
//       while(1); // HANG
//    }


    // For perfect time keeping calculations:
    // There must be NO-Code after time count is done
    // There must be (almost) no (time-consuming-code) below this line for actual run 
    // For a DRY RUN we can write code after this line

    if( DRY_RUN==1)
        {
            sprintf(str,"\r\n%4d E=%5d P=%6d I=%7d D=%6d O=%5d\t\tL=%3d R=%3d", 
                            lcv, error, pTerm, iTerm, dTerm, outputPID, leftMotorSpeed, rightMotorSpeed);
            DUMP_L1_a(str);
            delay(800); // If its not an actual run, observe the data on Terminal

        }

    lcv++;
}

/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
