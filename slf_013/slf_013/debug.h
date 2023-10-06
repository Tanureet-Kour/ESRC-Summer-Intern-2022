#ifndef _DEBUG_H_
    #define _DEBUG_H_

    //#include <Serial.h>
    #define BAUD_RATE  115200

    #define DEBUG_L1            1  // ALWAYS 1 : IMPORTANT MESSAGES
    #define DEBUG_L2            1  // More details: NOT so important messages
    #define DEBUG_SENSOR_ARRAY  1  // Do you want to debug / display Sensor array values


    #ifdef DEBUG_L1
        #define  DUMP_L1_a(a)       { Serial.print(a); Serial1.print(a); }
        #define  DUMP_L1_ab(a,b)    { Serial.print(a); Serial.print(b); Serial1.print(a); Serial1.print(b); }
        #define  DUMP_L1_abc(a,b,c) { Serial.print(a); Serial.print(b); Serial.print(c); Serial1.print(a); Serial1.print(b); Serial1.print(c);  }
    #else
        #define  DUMP_L1_a(a)       { ; }
        #define  DUMP_L1_ab(a,b)    { ; }
        #define  DUMP_L1_abc(a,b,c) { ; }
    #endif

    #ifdef DEBUG_L2
        #define  DUMP_L2_a(a)       { Serial.print(a); Serial1.print(a); }
        #define  DUMP_L2_ab(a,b)    { Serial.print(a); Serial.print(b); Serial1.print(a); Serial1.print(b); }
        #define  DUMP_L2_abc(a,b,c) { Serial.print(a); Serial.print(b); Serial.print(c); Serial1.print(a); Serial1.print(b); Serial1.print(c);  }
    #else
        #define  DUMP_L2_a(a)       { ; }
        #define  DUMP_L2_ab(a,b)    { ; }
        #define  DUMP_L2_abc(a,b,c) { ; }
    #endif

    #ifdef DEBUG_SENSOR_ARRAY
        #define  DUMP_SA_a(a)       { Serial.print(a); Serial1.print(a); }
        #define  DUMP_SA_ab(a,b)    { Serial.print(a); Serial.print(b); Serial1.print(a); Serial1.print(b); }
        #define  DUMP_SA_abc(a,b,c) { Serial.print(a); Serial.print(b); Serial.print(c); Serial1.print(a); Serial1.print(b); Serial1.print(c);  }
    #else
        #define  DUMP_SA_a(a)       { ; }
        #define  DUMP_SA_ab(a,b)    { ; }
        #define  DUMP_SA_abc(a,b,c) { ; }
    #endif


#endif // _DEBUG_H_