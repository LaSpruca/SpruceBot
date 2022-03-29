enum class LineFollowState : char {
    adjLeft,
    adjRight,
    turnLeft,
    turnRight,
    forward,
    stop
};

class LineFollow {
public:
    LineFollow(int leftPin, int rightPin);
    auto update() -> void;
    auto state() -> LineFollowState;
    auto prevState() -> LineFollowState;
private:
    LineFollowState _state;
    LineFollowState _prevState;
    int _pinLeft;
    int _pinRight;
};