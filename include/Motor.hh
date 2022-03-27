#pragma once

class Motor {
public:
  Motor(int motorPin1, int motorPin2);
  Motor(int motorPin1, int motorPin2, int motorPinSpeed);
  auto forward() -> void;
  auto backward() -> void;
  auto stop() -> void;
  auto setSpeed(int speed) -> void;
private:
  int _mp1;
  int _mp2;
  int _mps;
};