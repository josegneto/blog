/* LEDs and buttons test 
by josegneto.github.io */

const int button1 = 2; // 1st button
const int button2 = 3; // 2nd button
const int button3 = 4; // 3rd button
const int button4 = 5; // 4th button
const int led1 = 7;    // 1st button LED
const int led2 = 8;    // 2nd button LED
const int led3 = 9;    // 3rd button LED
const int led4 = 10;   // 4th button LED

int buttonState[4] = {0, 0, 0, 0};

void setup() {

  randomSeed(analogRead(0));
  pinMode(button1, INPUT); 
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  // Turn every LED ON
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  
  delay(2000);  

  // Turn every LED OFF
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

void loop(){

  // Store the button state into the array
  buttonState[0] = digitalRead(button1);
  buttonState[1] = digitalRead(button2);
  buttonState[2] = digitalRead(button3);
  buttonState[3] = digitalRead(button4);

  // Checkk if buttons were pressed
   
  if (buttonState[0] == HIGH) {
    // turn LED on:
    digitalWrite(led1, HIGH);
  }  
  if (buttonState[0] == LOW){
    // turn LED off:
    digitalWrite(led1, LOW);   
  }
   
  if (buttonState[1] == HIGH) {
    // turn LED on:
    digitalWrite(led2, HIGH);
  }  
  if (buttonState[1] == LOW){
    // turn LED off:
    digitalWrite(led2, LOW);   
  }

  if (buttonState[2] == HIGH) {
    // turn LED on:
    digitalWrite(led3, HIGH);
  }  
  if (buttonState[2] == LOW){
    // turn LED off:
    digitalWrite(led3, LOW);   
  }

  if (buttonState[3] == HIGH) {
    // turn LED on:
    digitalWrite(led4, HIGH);
  }  
  if (buttonState[3] == LOW){
    // turn LED off:
    digitalWrite(led4, LOW);   
  }
}