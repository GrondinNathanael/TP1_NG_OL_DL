#include "../lib/RGBLedManager/src/RGBLedManager.h"
#include <unity.h>

RGBLedManager rgb;
LED red = LED::RED;
LED orange = LED::ORANGE;
LED yellow = LED::YELLOW;
LED green = LED::GREEN;

void when_pm25_between_0_and_11_then_getColor_LED_green(void){
    TEST_ASSERT_EQUAL(green, rgb.getColor(9));
}

void when_pm25_between_12_and_34_then_getColor_LED_yellow(void){
    TEST_ASSERT_EQUAL(yellow, rgb.getColor(27));
}

void when_pm25_between_35_and_54_then_getColor_LED_orange(void){
    TEST_ASSERT_EQUAL(orange, rgb.getColor(41));
}

void when_pm25_55_and_over_then_getColor_LED_red(void){
    TEST_ASSERT_EQUAL(red, rgb.getColor(63));
}

void process() {
    UNITY_BEGIN();
    RUN_TEST(when_pm25_between_0_and_11_then_getColor_LED_green);
    RUN_TEST(when_pm25_between_12_and_34_then_getColor_LED_yellow);
    RUN_TEST(when_pm25_between_35_and_54_then_getColor_LED_orange);
    RUN_TEST(when_pm25_55_and_over_then_getColor_LED_red);
    UNITY_END();
}

#ifdef ARDUINO

#include <Arduino.h>
void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

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