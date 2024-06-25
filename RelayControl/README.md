/*
  RelayControl - Library for controlling multiple relays with a push button trigger.
  
  Author: URVISH SHAH
  Date Created: 25/06/2024
  Last Modified: 25/06/2024
  Version: 1.0
  
  Description:
  This library allows you to control multiple relays sequentially using a push button.
  Upon pressing the button, a sequence is initiated where each relay turns on for a
  specified duration, followed by a delay, and then turns off. Each relay can have its
  own trigger duration and interval between activations.

  Hardware Requirements:
  - Arduino board
  - Momentary push button
  - Relays (connected to appropriate pins)
  
  Connections:
  - Connect the push button to the specified pin (buttonPin).
  - Connect each relay to its respective pin in the relayPins array.

  Usage:
  - Create an instance of RelayControl with parameters for button pin, relay pins,
    number of relays, trigger durations, and intervals between activations.
  - Call begin() in setup() to initialize pins and Serial communication.
  - Call update() in loop() to handle relay sequencing based on button presses.

*/
