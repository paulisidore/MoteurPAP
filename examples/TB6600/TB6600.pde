#include <MoteurPAP.h>
//TB6600 microstep
//TB6600 Puls+ Pin connect to Arduino Pin 5 ;
//TB6600 Dir+ Pin connect to Arduino Pin 2 ;
//TB6600 En+ Pin connect to Arduino Pin 8 ;
MoteurPAP moteur(5,2,8);

void setup()
{
  Serial.println("Test du Driver TB6600") ;
  

}

void loop()
{
  moteur.Run(800,250,0); //800 Number of Pulse , 250 is for speed. decrease number for increase spead, 0 Direction can be 1 or 0
  delay(5000); //Run motor for 5 second
  moteur.Stop(); // Stop
  delay(2000);
  moteur.Run(800,150,1);
  delay(5000);
  moteur.Run(800,150,0);
  delay(2000);

  //
}

