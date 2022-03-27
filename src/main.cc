#include <Arduino.h>
#define d1s delay(2000)
#include <Robot.hh>


Robot robot(2,3,9,4,5,10);

void setup() {
    Serial.begin(9600);
    Serial.println("\n\n\nYeet!");

    Serial.println("robot.forward();");
    robot.forward();
    d1s;

    Serial.println("robot.backward();");
    robot.backward();
    d1s;

    Serial.println("robot.left();");
    robot.left();
    d1s;

    Serial.println("robot.forward();");
    robot.forward();
    d1s;
    
    Serial.println("robot.backward();");
    robot.backward();
    d1s;

    Serial.println("robot.right();");
    robot.right();
    d1s;

    Serial.println("robot.forwardLeft();");
    robot.forwardLeft();
    d1s;
    
    Serial.println("robot.backwardLeft();");
    robot.backwardLeft();
    d1s;
    
    Serial.println("robot.forwardRight();");
    robot.forwardRight();
    d1s;

    Serial.println("robot.backwardRight();");
    robot.backwardRight();
    d1s;

    robot.stop();
}

void loop() {}