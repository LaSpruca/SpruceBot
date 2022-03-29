#include <Robot.hh>

Robot::Robot(int m1p1, int m1p2, int m1sp, int m2p1, int m2p2, int m2sp) : _leftMotor(Motor(m1p1, m1p2, m1sp)), _rightMotor(Motor(m2p1, m2p2, m2sp)), _speed(255) {
    _resetSpeed();
}

auto Robot::forward() -> void {
    _resetSpeed();

    _leftMotor.forward();
    _rightMotor.forward();
}

auto Robot::backward() -> void {
    _resetSpeed();

    _leftMotor.backward();
    _rightMotor.backward();
}

auto Robot::left() -> void {
    _resetSpeed();

    _leftMotor.backward();
    _rightMotor.forward();
}

auto Robot::right() -> void {
    _resetSpeed();

    _leftMotor.forward();
    _rightMotor.backward();
}

auto Robot::stop() -> void {
    _resetSpeed();

    _leftMotor.stop();
    _rightMotor.stop();
}

auto Robot::forwardLeft() -> void {
    _leftMotor.setSpeed(_speed / 2);
    _rightMotor.setSpeed(_speed);

    _leftMotor.forward();
    _rightMotor.forward();
}

auto Robot::forwardRight() -> void {
    _leftMotor.setSpeed(_speed);
    _rightMotor.setSpeed(_speed / 2);

    _leftMotor.forward();
    _rightMotor.forward();

}

auto Robot::backwardLeft() -> void {
    _resetSpeed();

    _leftMotor.setSpeed(_speed / 2);

    _leftMotor.backward();
    _rightMotor.backward();
}

auto Robot::backwardRight() -> void {
    _resetSpeed();

    _rightMotor.setSpeed(_speed / 2);

    _leftMotor.backward();
    _rightMotor.backward();
}

auto Robot::setSpeed(int speed) -> void {
    _speed = speed;
    _resetSpeed();
}

void Robot::_resetSpeed() {
    _leftMotor.setSpeed(_speed);
    _rightMotor.setSpeed(_speed);
}