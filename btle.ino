#include <SPI.h>
#include <RF24.h>
#include <BTLE.h>
#include <stdio.h>

RF24 radio(9,10);

BTLE btle(&radio);

//char buffer = "ble";

char buffer[9] = "";
char fix[9] = "test";
int x=0;
long randNumber;
int randchannel;

void setup() {
  randomSeed(analogRead(0));
  Serial.begin(9600);
  while (!Serial) { }
  Serial.println("BTLE advertisement sender");
}

void loop() {
  btle.begin(buffer);
  randchannel = random(0, 3);
  btle.advertise(0,randchannel);
  Serial.print(randchannel);
  Serial.print(" ");
  btle.hopChannel();
  randNumber = random(10, 20);
  
  sprintf(buffer,"%s %u",fix,randNumber);

  //snprintf(buffer, 8, "%.1f test", analog);
  Serial.println(buffer);
  delay(100);
  buffer[7]++;
}

