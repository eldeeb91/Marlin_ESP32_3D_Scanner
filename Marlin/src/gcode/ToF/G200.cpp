#include <string>
#include <sstream>
using namespace std;
#include "../gcode.h"

#if ENABLED(Adafruit_VL53L0X_lib)
    #include <Adafruit_VL53L0X.h>
    Adafruit_VL53L0X lox = Adafruit_VL53L0X();

    bool started = false;
//    char  valuemm; notused

    void GcodeSuite::G200() {
        if (started== false){
            if (!lox.begin()) {
                SERIAL_ECHOLNPGM("Failed to boot VL53L0X[Adafruit_lib]");
                started= false;
            }//if
            else{
                //lox.configSensor(Adafruit_VL53L0X::VL53L0X_SENSE_HIGH_ACCURACY);
                SERIAL_ECHOLNPGM("VL53L0X Started[Adafruit_lib]");
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
#endif

#if ENABLED(vl53l0x_Arduino_lib)
    #include <Wire.h>
    #include <VL53L0X.h>

    VL53L0X sensor;
    #define HIGH_ACCURACY

    bool started = false;
    Wire.begin();

    void GcodeSuite::G200() {
        if (started== false){
            if (!sensor.init()){
                SERIAL_ECHOLNPGM("Failed to detect and initialize sensor!");
            }
            else{
                SERIAL_ECHOLNPGM("VL53L0X Started[Arduino_lib]");
                sensor.setTimeout(500);
                sensor.setMeasurementTimingBudget(200000);
                started= true;
            }//else
        }// if
        else{
            SERIAL_DECIMAL(sensor.readRangeSingleMillimeters()); // eldeeb 
            SERIAL_EOL(); 
            } // else
    } // void

#endif