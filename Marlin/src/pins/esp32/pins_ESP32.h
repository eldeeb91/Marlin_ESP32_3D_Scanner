/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Espressif ESP32 (Tensilica Xtensa LX6) pin assignments
 */

#include "env_validate.h"

#define BOARD_INFO_NAME "Espressif ESP32"

//
// I2S (steppers & other output-only pins)
//
// #define I2S_STEPPER_STREAM // eldeeb
// #if ENABLED(I2S_STEPPER_STREAM)
//   #define I2S_WS                              25
//   #define I2S_BCK                             26
//   #define I2S_DATA                            27
// #endif

//
// Limit Switches
//
#define X_MIN_PIN                             36 // eldeeb
#define Y_MIN_PIN                             39
#define Z_MIN_PIN                             34 // eldeeb

//
// Steppers
//
#define X_STEP_PIN                           25 // eldeeb
#define X_DIR_PIN                            02 // eldeeb
#define X_ENABLE_PIN                         19 // eldeeb
//#define X_CS_PIN                             0

#define Y_STEP_PIN                           05
#define Y_DIR_PIN                            18
#define Y_ENABLE_PIN                         19
//#define Y_CS_PIN                            13

#define Z_STEP_PIN                           00 // eldeeb
#define Z_DIR_PIN                            04 // eldeeb
#define Z_ENABLE_PIN                         19 // eldeeb
//#define Z_CS_PIN                             5  // SS_PIN

// #define E0_STEP_PIN                          137 // eldeeb
// #define E0_DIR_PIN                           138
// #define E0_ENABLE_PIN                        139
//#define E0_CS_PIN                           21

//
// Temperature Sensors
//
#define TEMP_0_PIN                            36  // Analog Input
#define TEMP_BED_PIN                          39  // Analog Input

//
// Heaters / Fans
//
#define HEATER_0_PIN                           2
#define FAN_PIN                               13
#define HEATER_BED_PIN                         4

// SPI
#define SDSS                                   5
