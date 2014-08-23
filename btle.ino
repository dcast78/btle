/*
Simple Bluetooth BLE arduino - nrf2401 test.

Used to broadcast value of mini solar panel tension.

Based on http://dmitry.gr/index.php?r=05.Projects&proj=15&proj=11.%20Bluetooth%20LE%20fakery post

and floe liberary for Arduino https://github.com/floe/BTLE

Download library RF24 and BTLE follwing instruction on https://github.com/floe/BTLE home page

Note: the BTLE class and the examples are licensed under GPLv3. However, the helper functions in btle.inc are (C) 2012 by Dmitry Grinberg under a separate license (see file for details).

*/

#include <SPI.h>
#include <RF24.h>
#include <BTLE.h>
#include <stdio.h>

RF24 radio(9,10);

BTLE btle(&radio);


char buffer[9] = "";
char fix[7] = "Power:";
int x=0;
int analog;

void setup() {
  randomSeed(analogRead(0));
  Serial.begin(9600);
  while (!Serial) { }
  Serial.println("BTLE solar power meter");
}

void loop() {
  btle.begin(buffer);
  btle.advertise(0,0);
  Serial.print(" ");
  btle.hopChannel();
  analog=analogRead(A0);  
  sprintf(buffer,"%s % 4u",fix,analog);

  //snprintf(buffer, 8, "%.1f test", analog);
  Serial.println(buffer);
  delay(30);
//  buffer[7]++;
}

