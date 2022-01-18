---
title: 'Servo'
date: '2018-08-20'
categories: ["Arduino"]
languages: ["C"]
spoiler: "Controlling a servo robot using an IR remote controller"
---


This project was developed during university summer break, after my first course using microcontrollers. 

It is based on [Controlling a Servo with IR](https://learn.adafruit.com/using-an-infrared-library/controlling-a-servo-with-ir-1) and [How to Set Up an IR Remote and Receiver on an Arduino](http://www.circuitbasics.com/arduino-ir-remote-receiver-tutorial/).

The objective is to control a Servo motor using an infrared controller.

---
## Phases: 
    
1. **Decode the controller**: obtain the code corresponding to each of the buttons so that the microcontroller knows which one is being pressed.

2. **Send instructions to the servo**, depending on which button is pressed:
    - Adjust the speed at which the motor will move.
    - Make the motor rotate to positions previously defined.

The work presented will not bring any major difficulties, as both the assembly and the code are easy to follow. Perhaps the decoding part is the most laborious, as we have to register about 28 codes (depending on the controller), which can become repetitive. 

[a](/download/IR_decoder.ino)
FAZER DOWNLAD CODIGO COM BOTAO
@@include[my-file.md](includes/my-file.md)

```c
/* Adapted from Examples -> IRremote -> IRrecvDemo by josegneto.github.io */

#include <IRremote.h>

const int RECV_PIN = 7; // Receptor Pin
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop()
{
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX); // Prints the HEX code in the Serial Monitor
    irrecv.resume();
  }
}
```
```jsx
function ExpensiveTree() {
  let now = performance.now();
  while (performance.now() - now < 100) {
    // Artificial delay -- do nothing for 100ms
  }
  return <p>I am a very slow component tree.</p>;
}
```




