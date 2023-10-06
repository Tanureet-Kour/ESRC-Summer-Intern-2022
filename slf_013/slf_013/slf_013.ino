// All Debug messages will be sent to both: USB and Bluetooth
#define PRINT    true
#define NO_PRINT false


#include "hal.h"
#include "debug.h"
#include "motor.h"
#include "QTRSensors.h"
#include "battery.h"
#include "utils.h"

/////////////////////////////////////////////////////////////////////////
int result[8];
/////////////////////////////////////////////////////////////////////////

void setup()
{
    init_GPIO();

//  motionForward(255);
//  delay(1000);
//  motionStop();
//  delay(2000);
//
//  motionReverse(255);
//  delay(1000);
//  motionStop();
//  delay(2000);

//    batteryVoltageCheck(1); // Check


    int count;
    long start_time, stop_time, diff_time;

    start_time = millis(); // Note the time
    for(count =1; count <= 100; count++)
    {
        getSensorArrayValues_OLD(&result[0], NO_PRINT);
    }
    stop_time = millis(); // Note the time again
    diff_time = stop_time - start_time;
    DUMP_L1_abc("\r\n The old version takes ", diff_time, " ms to give 100 readings");


    ////////////////////////////////////////////////////////////////////////////////////////////
    start_time = millis(); // Note the time
    for(count =1; count <= 100; count++)
    {
        getSensorArrayValues(&result[0], NO_PRINT);
    }
    stop_time = millis(); // Note the time again
    diff_time = stop_time - start_time;
    DUMP_L1_abc("\r\n The mordified version takes ", diff_time, " ms to give 100 readings");

    DUMP_L1_a("\r\n Press the RESET / RUN button to repeat the experiment");
    DUMP_L1_a("\r\n OBSERVE THESE RESULTS ON BLUETOOTH");

    while(1); // Remove this HANG after Viewing and understanding the output experiment 
    // OBSERVE THESE RESULTS ON BLUETOOTH
}
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
int i=0;
void loop()
{
    DUMP_L1_abc("\r\n", i++, "  "); // BT Prints ODD Numbers and USB Prints EVEN numbers think-Y


    // Uncomment any one line:
    DUMP_L1_a("\r\n");    getSensorArrayValues_OLD(&result[0], PRINT);
    
    //DUMP_L1_a("\r\n");    getSensorArrayValues(&result[0], PRINT);
    

    // NOTE both use different method so range of numbers fro White are different
    // Both are correct, just the "old" version consumes more time and is less precise
    //DUMP_L1_a("\r\n-------------------------------\r\n");



    
    
    batteryVoltageCheck(0); // Always Keep this line: 0= No Print, 1 = Print
    delay(500);
}
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
