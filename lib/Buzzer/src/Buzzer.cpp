#include <Arduino.h>
#include "Buzzer.h"

Buzzer::Buzzer() 
{       
  // Buzzer     
  ledcAttachPin(26, 0);
  // Bouton snooze
  pinMode(23, INPUT_PULLUP);
  // Source : https://github.com/espressif/arduino-esp32/issues/1720
  ledcSetup(0,1E5,12);
}

void Buzzer::ring(int nbParticles) 
{
  while (snoozeCountdown > 0)
  {
    ledcWriteTone(0,0);
    delay(1000);
    snoozeCountdown--;
  }
  if (nbParticles > 20)
  {
    ledcWriteTone(0,3000);
    // Nécessaire sinon le buzzer ne marche pas.
    delay(50);
    if (digitalRead(23) == LOW) snoozeCountdown = RESET_SNOOZE_COUNTDOWN;
    Serial.println(snoozeCountdown);
  }
}
