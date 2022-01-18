/* Adapted from Examples -> IRremote -> IRrecvDemo by josegneto.github.io */

#include <IRremote.h>

const int RECV_PIN = 7; // Receptor Pin
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX); // Prints the HEX code in the Serial Monitor
        irrecv.resume();
  }
}
