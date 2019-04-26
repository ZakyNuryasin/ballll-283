#include <SPI.h>
#include <Pixy.h>
#include <SoftwareSerial.h>
#include <TimerOne.h>
#include <Wire.h>
#include <HMC5883L.h>
#include <math.h>
#include "compass.h"
#include <Wire.h>
#include "Kalman.h" // Source: https://github.com/TKJElectronics/KalmanFilter
#define PI 3.14159265
#define X_CENTER        ((PIXY_MAX_X-PIXY_MIN_X)/2)
#define Y_CENTER        ((PIXY_MAX_Y-PIXY_MIN_Y)/2)
#define Address 0x60
#define LINE 200

unsigned long timer;

uint8_t buffer[2]; // I2C buffer

float derajat;
int anglefix;
int anglefix2;

SoftwareSerial stmSerial(10, 11);

void i2cWrite(uint8_t address, uint8_t registerAddress) {
  Wire.beginTransmission(address);
  Wire.write(registerAddress);
  Wire.endTransmission();
}

uint8_t* i2cRead(uint8_t address, uint8_t registerAddress, uint8_t nbytes) {
  Wire.beginTransmission(address);
  Wire.write(registerAddress);
  Wire.endTransmission();
  Wire.beginTransmission(address);
  Wire.requestFrom(address, nbytes);
  for (uint8_t i = 0; i < nbytes; i++)
    buffer[i] = Wire.read();
  Wire.endTransmission();
  return buffer;
}


double getAngleHigh() {
  uint8_t* data = i2cRead(Address, 2, 2);
  return (((data[0] << 8) + data[1]));
}

int kuadran1 = 121;
int kuadran2 = 971;
int kuadran3 = 1772;
int kuadran4 = 2697;

void cmpsLoop()
{
  double angleHigh = getAngleHigh();

  if ((angleHigh >= kuadran1) && (angleHigh < kuadran2))
  {
    anglefix = map(angleHigh, kuadran1, kuadran2, 0, 900);
  }
  if ((angleHigh >= kuadran2) && (angleHigh < kuadran3))
  {
    anglefix = map(angleHigh, kuadran2, kuadran3, 900, 1800);
  }
  else if ((angleHigh >= kuadran3) && (angleHigh < kuadran4))
  {
    anglefix = map(angleHigh, kuadran3, kuadran4, 1800, 2700);
  }
  else if ((angleHigh >= kuadran4) || (angleHigh < kuadran1))
  {
    if(angleHigh < kuadran1)
      angleHigh += 3599;
    
    anglefix = map(angleHigh, kuadran4, 3599 + kuadran1, 2700, 3599);
  }
//
//  Serial.print(angleHigh);
//  Serial.print("        ");
//  Serial.println(anglefix);

//  if(stmSerial.available())
//    stmSerial.read();

  anglefix2 = anglefix % 100;
  anglefix = anglefix / 100;
}



void interruptHandler() {
  uint8_t heading;
  char sendBuffer[10];

  sendBuffer[4] = 'C';
  sendBuffer[5] = anglefix;
  sendBuffer[6] = 'O';
  sendBuffer[7] = anglefix2;

  
  Serial.write(sendBuffer[4]);
  Serial.write(sendBuffer[5]);
  Serial.write(sendBuffer[6]);
  Serial.write(sendBuffer[7]);

  stmSerial.write(sendBuffer[4]);
  stmSerial.write(sendBuffer[5]);
  stmSerial.write(sendBuffer[6]);
  stmSerial.write(sendBuffer[7]);
}

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  stmSerial.begin(9600);
  Serial.print("Starting...\n");

  Timer1.initialize(50000);
  Timer1.attachInterrupt(interruptHandler);

  
}

void loop()
{
    cmpsLoop();
    delay(200);
}

