#include <Servo.h>

const int servoPin = 9; 
const int t = 1000; 


int servoAngle = 0;


Servo servo; 


void potensiometer(){
    servoAngle = analogRead(A0);
    servoAngle = map(servoAngle,0,1024,0,180);
}

void styreServo(){
    servo.write(servoAngle);
}

void setup(){
    servo.attach(servoPin);

}

void loop() {
    potensiometer();
    styreServo();
}
