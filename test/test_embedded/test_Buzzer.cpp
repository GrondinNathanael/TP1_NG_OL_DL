#include "../lib/Buzzer/src/Buzzer.h"
#include <unity.h>
#include <Arduino.h>

Buzzer buzzer;

void when_pm25_less_than_20_then_buzzer_not_ring(void){
    TEST_ASSERT_EQUAL(false, buzzer.ring(19));
}

void when_pm25_above_20_then_buzzer_ring(void){
    TEST_ASSERT_EQUAL(true, buzzer.ring(21));
}

void when_pm25_less_than_20_then_cannot_snooze(void){
    digitalWrite(23, LOW);
    buzzer.ring(19);
    TEST_ASSERT_EQUAL(true, buzzer.ring(19));
}

void when_pm25_above_20_then_can_snooze(void){
    digitalWrite(23, LOW);
    buzzer.ring(21);
    TEST_ASSERT_EQUAL(false, buzzer.ring(21));
}

void process() {
    UNITY_BEGIN();
    RUN_TEST(when_pm25_less_than_20_then_buzzer_not_ring);
    RUN_TEST(when_pm25_above_20_then_buzzer_ring);
    RUN_TEST(when_pm25_less_than_20_then_cannot_snooze);
    RUN_TEST(when_pm25_above_20_then_can_snooze);
    UNITY_END();
}

#ifdef ARDUINO

void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);
    // Buzzer     
    ledcAttachPin(26, 0);
    // Bouton snooze
    pinMode(23, INPUT_PULLUP);
    // Source : https://github.com/espressif/arduino-esp32/issues/1720
    ledcSetup(0,1E5,12);

    process();
}

void loop() {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(500);
}

#else

int main(int argc, char **argv) {
    process();
    return 0;
}

#endif