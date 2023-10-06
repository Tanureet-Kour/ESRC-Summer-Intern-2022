#ifndef _QTR_SENSORS_H_
    #define _QTR_SENSORS_H_

    #include <Arduino.h>
    //#include <Serial.h>
    #include "hardware/gpio.h"
    #include "hal.h"
    #include "debug.h"

    #define MAX_TIME 1000

    const int photoDiodePins[8] = { IR_D1_PIN_NO, IR_D2_PIN_NO, IR_D3_PIN_NO, IR_D4_PIN_NO,
                                    IR_D5_PIN_NO, IR_D6_PIN_NO, IR_D7_PIN_NO, IR_D8_PIN_NO };

    void getSensorArrayValues(int result[], bool print);
    void getSensorArrayValues_OLD(int result[], bool print);
    

#endif // _QTR_SENSORS_H_