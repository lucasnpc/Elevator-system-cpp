class Elevator
{
    int currentFloor, previousFloor;
    float maxWeight, currentWeight;
    bool moving;
public:
    Elevator() {};
    Elevator(float weight) : currentFloor(1), previousFloor(0), maxWeight(weight), moving(false), currentWeight(0) {};
    ~Elevator() {};
    int GetCurrentFloor() { return currentFloor; }
    int GetPreviousFloor() { return previousFloor; }
    void SetPreviousFloor(int _floor) { previousFloor = _floor; }
    float GetCurrentWeight() { return currentWeight; }
    void AddCurrentWeight(float weight) { currentWeight += weight; }
    void RemoveCurrentWeight(float weight) { currentWeight -= weight; }
    float GetMaxWeight() { return maxWeight; }
    void MovingDown() {
        moving = true;
        --currentFloor;
    }
    void MovingUp() {
        moving = true;
        ++currentFloor;
    }
    void StopMoving() {
        moving = false;
    }
    bool IsMoving() { return moving; }
};
