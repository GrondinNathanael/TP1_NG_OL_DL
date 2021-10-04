#include <Arduino.h>
#include "Buzzer.h"

Buzzer::Buzzer() 
{       
  
}

bool Buzzer::ring(int nbParticles) 
{
  if (snoozeCountdown > 0)
  {
    ledcWriteTone(0,0);
    snoozeCountdown--;
    return false;
  }
  else if (nbParticles > 20)
  {
    ledcWriteTone(0,3000);
    // Nécessaire sinon le buzzer ne marche pas.
    delay(50);
    if (digitalRead(23) == LOW) snoozeCountdown = RESET_SNOOZE_COUNTDOWN;
    Serial.println(snoozeCountdown);
    return true;
  }
  return false;
}
