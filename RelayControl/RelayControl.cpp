#include "RelayControl.h"

RelayControl::RelayControl(int buttonPin, int* relayPins, int numRelays, long* intervalTriggers, long* intervalsBetween) {
  _buttonPin = buttonPin;
  _relayPins = relayPins;
  _numRelays = numRelays;
  _intervalTriggers = intervalTriggers;
  _intervalsBetween = intervalsBetween;
  
  _startTimes = new unsigned long[numRelays];
  _relayActive = new bool[numRelays];
}

void RelayControl::begin() {
  pinMode(_buttonPin, INPUT);
  for (int i = 0; i < _numRelays; i++) {
    pinMode(_relayPins[i], OUTPUT);
    digitalWrite(_relayPins[i], LOW);
    _relayActive[i] = false;
  }
  Serial.begin(9600);
  Serial.println("Setup complete. Waiting for button press...");
}

void RelayControl::update() {
  if (digitalRead(_buttonPin) == HIGH) {
    startSequence();
  }

  unsigned long currentMillis = millis();
  for (int i = 0; i < _numRelays; i++) {
    controlRelay(i, currentMillis);
  }
}

void RelayControl::startSequence() {
  for (int i = 0; i < _numRelays; i++) {
    _startTimes[i] = millis() + (_intervalsBetween[i] * i);
    _relayActive[i] = true;
    digitalWrite(_relayPins[i], HIGH);
    Serial.print("Relay ");
    Serial.print(i + 1);
    Serial.println(" ON");
  }
}

void RelayControl::controlRelay(int relayIndex, unsigned long currentMillis) {
  if (_relayActive[relayIndex] && (currentMillis - _startTimes[relayIndex] >= _intervalTriggers[relayIndex])) {
    digitalWrite(_relayPins[relayIndex], LOW);
    Serial.print("Relay ");
    Serial.print(relayIndex + 1);
    Serial.println(" OFF");
    _relayActive[relayIndex] = false;
  }
}
