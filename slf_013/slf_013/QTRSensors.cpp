#include "QTRSensors.h"

void getSensorArrayValues(int result[], bool print)
{
// QTR-8RC line detector (IR LINE TRACKER)
//
// REFERENCE:
//
// https://raspberrypi.github.io/pico-sdk-doxygen/group__hardware__gpio.html#gae895be2d3c5af5df460150eafe7858a4
//
// https://shop.mchobby.be/en/motor-robotic/497-detecteur-de-ligne-ir-line-tracker-3232100004979-pololu.html
//

    int index;
    //register int time;
    int time;

    uint32_t quadByte;
    uint32_t quadBytePrevious;
    uint32_t changedBits;

    // int totalChanges =0;


    // On RPi Pico GPIO mArk the pins of interest by "1"
    //
    //       D1, D2, D3, D4, D5, D6, D7, D8
    //        9,  8,  7,  6,  5,  4,  3,  2
    //
    //  
    //
    //       0000-0011-1111-1100
    //          0    3    F    C

    uint32_t mask_PhotoDiodeAndCapPins = 0x03FC;

    for(index=0; index <= 7; index++)  // Initialize result array
        result[index] =  MAX_TIME;     // Assume all Black

    // STEP: Charge the capacitors of the ALL sensors, by applying a voltage to the OUT pin
    gpio_set_dir_out_masked(mask_PhotoDiodeAndCapPins); // Switch all GPIOs in "mask" as OUTPUT
    gpio_set_mask(mask_PhotoDiodeAndCapPins);           // Drive high every GPIO appearing in mask
    delayMicroseconds(20);                              // This will charge all the Capacitors
        
    // STEP: Count the time taken to discharge the capacitor:
    //       White discharges fast: Lower count
    //       Black discharges slow: High cout or MAX
    //       In other words:
    //         Increment time until this pin gets low again,
    //         If its taking too much time, stop incrementing time, assume it as black
    //       OLD code: NOT relavent now:
    //        while( (digitalRead(photoDiodePins[sno]) != LOW) && (time < MAX_TIME) )
    //            time++;

    gpio_set_dir_in_masked(mask_PhotoDiodeAndCapPins); // Switch all GPIOs in "mask" as INPUT
    quadByte = gpio_get_all(); // READ All input pins

    quadByte = quadByte & mask_PhotoDiodeAndCapPins; // Keep only pins of interest, Zero-out others

                              // Pin 0 and 1 are of UART
    quadByte = quadByte >> 2; // After this shift we get sensor values properly arranged from MSB to LSB
    quadBytePrevious = quadByte;

    // STEP: Switch ON IR LEDs
    digitalWrite(IR_ON_PIN_NO, HIGH);  // HIGH = ON

    time = 0;
    while (time < MAX_TIME)
    {
        time++;

        quadByte = gpio_get_all();
        quadByte = quadByte & mask_PhotoDiodeAndCapPins;

        quadByte = quadByte >> 2;

        if( quadByte == quadBytePrevious)
            continue;

        changedBits = quadByte ^ quadBytePrevious; // XOR: All changed bits becoms 1, unchanged bits becomes 0

        index =7; 
        while(changedBits) // For all changed bits: Save the result
        {
            if(changedBits & 0x0001)
            {
               // STEP: Save Result for the n'th sensor:
               result[index] = time;            
            }
            changedBits = changedBits >> 1;
            index--;        
        }

        quadBytePrevious = quadByte;
    }

    // STEP: Switch OFF IR LEDs
    digitalWrite(IR_ON_PIN_NO, LOW);

    // STEP: Display Result
    if(print)
        for(index=7; index >=0; index--)
        {
            DUMP_SA_ab(" D", index+1);  DUMP_SA_ab(" = ", result[index]);
        }
}
/////////////////////////////////////////////////////////////////////////

void getSensorArrayValues_OLD(int result[], bool print)
{
// Reference: https://shop.mchobby.be/en/motor-robotic/497-detecteur-de-ligne-ir-line-tracker-3232100004979-pololu.html
// QTR-8RC line detector (IR LINE TRACKER
    int sno;
    //register int time;
     int time;

    // STEP: Switch ON IR LEDs
    digitalWrite(IR_ON_PIN_NO, HIGH);  // HIGH = ON
    delayMicroseconds(20);

    for(sno =7; sno>=0; sno--)
    {        
        time = 0;
        
        // STEP: Charge the capacitor of the n'th sensor, by applying a voltage to the OUT pin
        pinMode(photoDiodePins[sno], OUTPUT);
        digitalWrite(photoDiodePins[sno], HIGH);
        //delayMicroseconds(20);
        delay(1);

        // STEP: Count the time taken to discharge the capacitor: 
        //       White discharges fast: Lower count
        //       Black discharges slow: High cout
        pinMode(photoDiodePins[sno], INPUT);
        while( (digitalRead(photoDiodePins[sno]) != LOW) && (time < MAX_TIME) )
            time++;

        // STEP: Save Result for the n'th sensor:
        result[sno] = time;            

        // STEP: Display Result 
        if(print)
            { DUMP_SA_ab(" S", sno+1);  DUMP_SA_ab(" = ", time);  }

    }
        

    // STEP: Switch OFF IR LEDs
    digitalWrite(IR_ON_PIN_NO, LOW);

// To use the sensor, you must first activate the reading pin of 
// your microcontroller as output to charge the capacity of the node 
// by applying a voltage to the OUT pin

//STEP: Read the reflectance:  by re-reading 
// the voltage on this pin by reconfiguring the pin as input.

// STEP:  The capacitor will discharge through the photo-transistor ... 
// this discharge doing this more or less quickly depending on the reflecting 
// surface exciting the phototransistor.
// The voltage on the OUT pin will drop more or less quickly. 
// It is therefore sufficient to measure the time necessary for the voltage to 
// drop enough to bring the OUT pin back to the low state. 
// This time is a good indicator of the infrared light returned to the 
// infrared sensor (photo-transistor) and therefore of the type of 
// reflecting surface under the sensor.
// A short decay time means greater reflection of the surface.


}

/////////////////////////////////////////////////////////////////////////
