/*
   This program makes use of code from the following source: https://github.com/Seeed-Studio/Grove_Temperature_Sensor
                                                             Copyright (c) 2013 Seeed Technology Inc.
*/

/*
   The program reads data in the form of resistance, from a temperature sensor
   attached to a Grove Base shield, which is attached to an Intel Edison + Arduino breakout kit.
   It converts the data to temperature (in Celsius) and prints the data (encoded in ASCII) to the serial port.

   The sensor is connected to the A0.
   A different program reads and displays the data in Wolfram Mathematica.
*/

#include <Wire.h>                                       // Wire library allows communication with I2C devices

const int B = 3975;                                     // define B-value of thermistor

void setup()
 {
   Serial.begin(115200);                                // rate at which data is transferred (in bits/s)
   Wire.begin();
 }

 void loop()
 {
   int val = analogRead(A0);                             // read data from pin A0
   float resistance = (float)(1023-val)*10000/val;       // calculate resistance
   float temperature = 1/(log(resistance/10000)/B+1/298.15)-273.15;   // calculate temperature

   Serial.print(temperature);                            // print this value to serial port
   Serial.print("\n");

   delay(1000);                                          // wait 1s & repeat
 }
