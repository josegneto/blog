/*  Adapted from Examples -> IRLib2 -> servo 
by josegneto.github.io */

#include <IRLibAll.h>
#include <Servo.h>

// You will have to set these values depending on the protocol
// and remote codes that you are using

#define MY_PROTOCOL NEC
#define CH-           0x1FE48B7
#define CH            0x1FE58A7
#define CH+           0x1FE7887
#define FAST_BACKWARD 0x1FE807F     // Move the servo counterclockwise
#define FAST_FORWARD  0x1FE40BF     // Move the servo clockwise
#define PLAY_PAUSE    0x1FEC03F     // Center the servo
#define VOLDEC        0x1FE20DF     // Decrease the speed (number of degrees) at which the servo turns
#define VOLINC        0x1FEA05F     // Increase the speed (number of degrees) at which the servo turns
#define EQ            0x1FE609F
#define BUTTON_0      0x1FEE01F     // Pressing the 0-9 buttons rotates key_value * 20 degrees at a time
#define BUTTON_1      0x1FE50AF     // User defined position
#define BUTTON_2      0x1FED827
#define BUTTON_3      0x1FEF807
#define BUTTON_4      0x1FE30CF
#define BUTTON_5      0x1FEB04F
#define BUTTON_6      0x1FE708F
#define BUTTON_7      0x1FE00FF
#define BUTTON_8      0x1FEF00F
#define BUTTON_9      0x1FE9867

IRrecv myReceiver(11); // Receiver pin
IRdecode myDecoder;

Servo myServo;     // Create servo object to control a servo
int16_t pos;       // Variable to store the servo position
int16_t Speed;     // Number of degrees to move each time a left/right button is pressed
uint32_t Previous; // Handles NEC repeat codes

void setup()
{
  myServo.attach(9);       // Attaches the servo on pin 9 to the servo object
  pos = 90;                // Start at midpoint 90 degrees
  Speed = 3;               // Servo moves 3 degrees each time left/right is pushed
  myServo.write(pos);      // Set initial position
  myReceiver.enableIRIn(); // Start the receiver
}

void loop() 
{ 
    if (myReceiver.getResults()) {
       myDecoder.decode();
       if(myDecoder.protocolNum==MY_PROTOCOL) {
         if(myDecoder.value==0xFFFFFFFF)
           myDecoder.value=Previous;
         switch(myDecoder.value) {
            case FAST_BACKWARD: pos=min(180,pos+Speed); break;
            case FAST_FORWARD:  pos=max(0,pos-Speed); break;
            case PLAY_PAUSE:    pos=90; break;
            case VOLDEC:       Speed=min(10, Speed+1); break;
            case VOLINC:      Speed=max(1, Speed-1); break;
            case BUTTON_0:      pos=0*20; break;
            case BUTTON_1:      pos=1*20; break;
            case BUTTON_2:      pos=2*20; break;
            case BUTTON_3:      pos=3*20; break;
            case BUTTON_4:      pos=4*20; break;
            case BUTTON_5:      pos=5*20; break;
            case BUTTON_6:      pos=6*20; break;
            case BUTTON_7:      pos=7*20; break;
            case BUTTON_8:      pos=8*20; break;
            case BUTTON_9:      pos=9*20; break;
         }
         myServo.write(pos); // Tell servo to go to position in variable 'pos' 
         Previous=myDecoder.value;
       }
       myReceiver.enableIRIn();
    }
}