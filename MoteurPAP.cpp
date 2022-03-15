/*
  MoteurPAP.cpp - Library for driving External Stepper Driver like TB6600.
  Created by Paul Isidore A. NIAMIE, March 14, 2022.
  Released into the public domain.
*/

#include "Arduino.h"
#include "MoteurPAP.h"

MoteurPAP::MoteurPAP(int pinStep,int pinDir,int pinEn)
{
  pinMode(pinStep, OUTPUT);
  _stepPin = pinStep;
  _dirPin=pinDir;
  _enPin=pinEn;
  Ready=0;
}

void MoteurPAP::Init()
{
    digitalWrite(_enPin,HIGH);
    delay(100);
    digitalWrite(_enPin,LOW);
    MoteurPAP::Ready=1;
}
void MoteurPAP::Run(int NbPulsion,int Vitesse=250,int Direction=0)
{
  if (Ready==0){
    Init();
  }
  digitalWrite(_dirPin,Direction);
  for (int x=0;x<NbPulsion;x++){
      digitalWrite(_stepPin,HIGH);
      delayMicroseconds(Vitesse); 
      digitalWrite(_stepPin,LOW); 
      delayMicroseconds(Vitesse);
  }  
}

void MoteurPAP::Stop()
{
  digitalWrite(_stepPin, LOW);
  delay(50);
}

void MoteurPAP::Engage(int ONOFF)
{
  digitalWrite(_enPin, ONOFF);
  delay(50);
}
