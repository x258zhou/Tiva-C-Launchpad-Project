#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>
#include <string.h>
#include "defines.h"
#include <stdlib.h>

/****************************************************************************
 *                                                                          *
 *                              SUPER MARIO                                 *
 *                                 DASH!                                    *
 *                                 DASH!                                    *
 *                                 DASH!                                    *
 *                                                                          *
 ****************************************************************************
 *                                                                          *
 * * This project is created for SE 101 LAB Project.                        *
 * * Author: Xiao Zhou                                                      *
 *          Zhiqing Hu                                                      *
 * * Software Engineering                                                   *
 * * University of Waterloo                                                 *
 * * Nov. 30, 2016                                                          *
 *                                                                          *
 ****************************************************************************/
 
const int buttonPin1 = 18;
const int buttonPin2 = 25;
int buttonState1 = 0;
int buttonState2 = 0;
const int ledPin = GREEN_LED;

void setup() 
{
  Serial.begin(BAUD_RATE);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLDOWN);
  pinMode(buttonPin2, INPUT_PULLDOWN);
  randomSeed(analogRead(0));
  oledInit();
  welcomeScreen();
  waitForButton();
  
}

void loop() 
{
  randomSeed(analogRead(0));
  loading();
  waitForButton();
  delay(100);
  int score = mainGame();
  gameOver(score);
  waitForButton();
}

