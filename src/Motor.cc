#include "Motor.hh"
#include <Arduino.h>
#include <math.h>

// Constructor for a Motor
Motor::Motor(int mp1, int mp2) : _mp1(mp1), _mp2(mp2), _mps(-1) {
  pinMode(mp1, OUTPUT);
  pinMode(mp2, OUTPUT);
}

Motor::Motor(int mp1, int mp2, int mps) : _mp1(mp1), _mp2(mp2), _mps(mps) {
  pinMode(mp1, OUTPUT);
  pinMode(mp2, OUTPUT);
}

auto Motor::forward() -> void {
  digitalWrite(_mp1, LOW);
  digitalWrite(_mp2, HIGH);
}

auto Motor::backward() -> void {
  digitalWrite(_mp1, HIGH);
  digitalWrite(_mp2, LOW);
}

auto Motor::stop() -> void {
    digitalWrite(_mp1, LOW);
    digitalWrite(_mp2, LOW);
}

auto Motor::setSpeed(int speed) -> void {
  if (_mps != -1) {
    analogWrite(_mps, speed);
  }
}