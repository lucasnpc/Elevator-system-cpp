class Elevator
{
    int currentFloor, previousFloor;
    float maxWeight;
public:
    Elevator() {};
    Elevator(float weight) : currentFloor(1), previousFloor(-1), maxWeight(weight) {};
    ~Elevator() {};
};
