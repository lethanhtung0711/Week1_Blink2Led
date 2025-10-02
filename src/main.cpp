#include <Arduino.h>
#include <OneButton.h>

#define LED1_PIN 5
#define LED2_PIN 6
#define BUTTON_PIN 4
OneButton button(BUTTON_PIN, true);

bool controllingLED1 = true;

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  button.attachClick(toggleLED);
  button.attachDoubleClick(changeLED);
  button.attachDuringLongPress(blinkLED);
}
void loop() {
  button.tick();
}
void toggleLED() {
  if (controllingLED1) {
    digitalWrite(LED1_PIN, !digitalRead(LED1_PIN));
  } else {
    digitalWrite(LED2_PIN, !digitalRead(LED2_PIN));
  }
}
void changeLED() {
  controllingLED1 = !controllingLED1;
}
void blinkLED() {
  int blinkInterval = 200;
  unsigned long currentMillis = millis();
  static unsigned long previousMillis = 0;

  if (currentMillis - previousMillis >= blinkInterval) {
    previousMillis = currentMillis;
    if (controllingLED1) {
      digitalWrite(LED1_PIN, !digitalRead(LED1_PIN));
    } else {
      digitalWrite(LED2_PIN, !digitalRead(LED2_PIN));
    }
  }
}
