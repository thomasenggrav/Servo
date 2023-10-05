#include <Servo.h>

const int servoPin = 9; 
const int t = 1000; 

unsigned long MOVING_TIME = 1800;
unsigned long moveStartTime; 

int startAngle = 0;
int stopAngle = 180; 

Servo servo; 

void scan(){
    unsigned long progress = millis() - moveStartTime; 

    if (progress <= MOVING_TIME){
        long angle = map(progress, 0, MOVING_TIME, startAngle, stopAngle);
        servo.write(angle);
        if (angle == 180){
            long angle = map(progress, 0, MOVING_TIME, stopAngle, startAngle);
            servo.write(angle);
            moveStartTime = millis();
        }
    } 
}



void setup(){
    servo.attach(servoPin);
    moveStartTime = millis();

}

void loop() {
    scan();
}
