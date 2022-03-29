#pragma once
#include <Motor.hh>
#include <LineFollow.hh>

class Robot {
public:
    Robot(int leftMotorPin1, int leftMotorPin2, int leftMotorSpeed, int rightMotorPin1, int rightMotorPin2, int rightMotorSpeed);
    auto forward() -> void;
    auto backward() -> void;
    auto left() -> void;
    auto right() -> void;
    auto stop() -> void;

    auto forwardLeft() -> void;
    auto forwardRight() -> void;
    auto backwardLeft() -> void;
    auto backwardRight() -> void;

    auto setSpeed(int speed) -> void;
private:
    auto _resetSpeed() -> void;

    Motor _leftMotor;
    Motor _rightMotor;
    int _speed;
};