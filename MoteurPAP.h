/*
  MoteurPAP.h - Library for driving External Stepper Driver like TB6600.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#ifndef MoteurPAP_h
#define MoteurPAP_h
#include "Arduino.h"

class MoteurPAP
{
  public:
    MoteurPAP(int pinStep,int pinDir,int pinEn);
    void Init();
    void Run(int NbPulsion,int Vitesse,int Direction);
    void Stop();
    void Engage(int ONOFF);
    int Ready;
  private:
    int _stepPin;
    int _dirPin;
    int _enPin;
    
};

#endif

