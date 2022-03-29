#include <Arduino.h>
#include <LineFollow.hh>

LineFollow::LineFollow(int leftPin, int rightPin)
    : _state(LineFollowState::stop), _prevState(LineFollowState::stop),
      _pinLeft(leftPin), _pinRight(rightPin) {
  pinMode(leftPin, INPUT);
  pinMode(rightPin, INPUT);
}

auto LineFollow::prevState() -> LineFollowState {
  auto ret = (LineFollowState)_state;
  return ret;
}

auto LineFollow::state() -> LineFollowState {
  auto ret = (LineFollowState)_state;
  return ret;
}

auto LineFollow::update() -> void {
  auto leftState = !digitalRead(_pinLeft);
  auto rightState = !digitalRead(_pinRight);

  LineFollowState state = LineFollowState::stop;

  // If both sensors on line
  if (leftState && rightState) {
    state = LineFollowState::forward;

  }
  // If no sensor on line
  else if (!leftState && !rightState) {
    // If any form of left turn
    if (_prevState == LineFollowState::adjLeft ||
        _prevState == LineFollowState::turnLeft) {
      state = LineFollowState::turnLeft;
    }
    // If any form of right turn
    else if (_prevState == LineFollowState::adjRight ||
             _prevState == LineFollowState::turnRight) {
      state = LineFollowState::turnRight;
    }
    // If was heading straight
    else if (_prevState == LineFollowState::forward) {
      state = LineFollowState::turnLeft;
    }
  }
  // If only left
  else if (!leftState && rightState) {
    state = LineFollowState::adjRight;
  } 
  // If only right
  else if (leftState && !rightState) {
    state = LineFollowState::adjLeft;
  } else {
    if (state == LineFollowState::adjLeft ||
        state == LineFollowState::turnLeft) {
      state = LineFollowState::turnLeft;
    } else if (state == LineFollowState::adjRight ||
               state == LineFollowState::turnRight) {
      state = LineFollowState::turnRight;
    }
  }

  if (state != _prevState) {
    _prevState = _state;
  }

  _state = state;
}
