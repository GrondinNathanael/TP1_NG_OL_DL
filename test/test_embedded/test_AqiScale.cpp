#include "../lib/AqiScale/src/AqiScale.h"
#include <unity.h>

AqiScale scale;

void when_pm25_equals_11_then_getAQILabelFromPM25_result_bon(void){
    TEST_ASSERT_EQUAL(0, scale.bon.description.compareTo(scale.getAQILabelFromPM25(11).description));
}

void when_pm25_equals_34_then_getAQILabelFromPM25_result_acceptable(void){
    TEST_ASSERT_EQUAL(0, scale.acceptable.description.compareTo(scale.getAQILabelFromPM25(34).description));
}

void when_pm25_equals_54_then_getAQILabelFromPM25_result_mauvaisGroupeSensible(void){
    TEST_ASSERT_EQUAL(0, scale.mauvaisGroupeSensible.description.compareTo(scale.getAQILabelFromPM25(54).description));
}

void when_pm25_equals_149_then_getAQILabelFromPM25_result_mauvaisPourSante(void){
    TEST_ASSERT_EQUAL(0, scale.mauvaisPourSante.description.compareTo(scale.getAQILabelFromPM25(149).description));
}

void when_pm25_equals_249_then_getAQILabelFromPM25_result_tresMauvais(void){
    TEST_ASSERT_EQUAL(0, scale.tresMauvais.description.compareTo(scale.getAQILabelFromPM25(249).description));
}

void when_pm25_equals_250_then_getAQILabelFromPM25_result_Dangereux(void){
    TEST_ASSERT_EQUAL(0, scale.Dangereux.description.compareTo(scale.getAQILabelFromPM25(250).description));
}

void process() {
    UNITY_BEGIN();
    RUN_TEST(when_pm25_equals_11_then_getAQILabelFromPM25_result_bon);
    RUN_TEST(when_pm25_equals_34_then_getAQILabelFromPM25_result_acceptable);
    RUN_TEST(when_pm25_equals_54_then_getAQILabelFromPM25_result_mauvaisGroupeSensible);
    RUN_TEST(when_pm25_equals_149_then_getAQILabelFromPM25_result_mauvaisPourSante);
    RUN_TEST(when_pm25_equals_249_then_getAQILabelFromPM25_result_tresMauvais);
    RUN_TEST(when_pm25_equals_250_then_getAQILabelFromPM25_result_Dangereux);
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