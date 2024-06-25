#ifndef RelayControl_h
#define RelayControl_h

#include <Arduino.h>

class RelayControl {
  public:
    RelayControl(int buttonPin, int* relayPins, int numRelays, long* intervalTriggers, long* intervalsBetween);
    void begin();
    void update();

  private:
    int _buttonPin;
    int* _relayPins;
    int _numRelays;
    long* _intervalTriggers;
    long* _intervalsBetween;
    unsigned long* _startTimes;
    bool* _relayActive;

    void startSequence();
    void controlRelay(int relayIndex, unsigned long currentMillis);
};

#endif
