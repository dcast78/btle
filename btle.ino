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

