#include <Arduino.h>
#include <Robot.hh>
#include <Servo.h>

Servo servo;

LineFollow lineFollow(6, 7);

Robot robot(A0, A1, 9, A2, A3, 10);

auto stringFromState(LineFollowState state) -> String {
  switch (state) {
  case LineFollowState::forward:
    return "LineFollowState::forward";
    break;
  case LineFollowState::stop:
    return "LineFollowState::stop";
    break;
  case LineFollowState::adjLeft:
    return "LineFollowState::adjLeft";
    break;
  case LineFollowState::adjRight:
    return "LineFollowState::adjRight";
    break;
  case LineFollowState::turnLeft:
    return "LineFollowState::turnLeft";
    break;
  case LineFollowState::turnRight:
    return "LineFollowState::turnRight";
    break;
  }

  return "";
}

auto setup() -> void {
  Serial.begin(9600);
  robot.setSpeed(60);
  robot.stop();

  servo.attach(3);

  servo.write(50);

  delay(1000);

  servo.write(160);
}

auto loop() -> void {

  lineFollow.update();
  Serial.println("---");
  Serial.println(stringFromState(lineFollow.state()));
  Serial.println(stringFromState(lineFollow.prevState()));
  Serial.println("---");

  switch (lineFollow.state()) {
  case LineFollowState::forward:
    robot.forward();
    break;
  case LineFollowState::stop:
    robot.stop();
    break;
  case LineFollowState::adjLeft:
    robot.forwardLeft();
    break;
  case LineFollowState::adjRight:
    robot.forwardRight();
    break;
  case LineFollowState::turnLeft:
    robot.left();
    break;
  case LineFollowState::turnRight:
    robot.right();
    break;
  }
}