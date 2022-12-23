#include <string>
#include <sstream>
using namespace std;
#include "../gcode.h"
#include <Adafruit_VL53L0X.h>

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

bool started = false;
char  valuemm;

void GcodeSuite::G200() {
    if (started== false){
        if (!lox.begin()) {
            SERIAL_ECHOLNPGM("Failed to boot VL53L0X");
            started= false;
        }//if
        else{
            SERIAL_ECHOLNPGM("VL53L0X Started");
            started= true;
        }//else
    }// if
    else{
        VL53L0X_RangingMeasurementData_t measure;
        lox.rangingTest(&measure, false);
        if (measure.RangeStatus != 4) {
            //SERIAL_ECHOLNPGM(measure.RangeMilliMeter);
            SERIAL_DECIMAL(measure.RangeMilliMeter); // eldeeb 
            SERIAL_EOL();
        }
        else {
            SERIAL_ECHOLNPGM("NaN");
        }   

        } // else
    } // void
