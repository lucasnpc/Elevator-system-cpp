#include "elevator.h"
#include <map>
#include <string>
#include <deque>

class ElevatorUsecase
{
    std::map<std::string, Elevator> elevators;
    std::map<std::string, std::deque<int>> elevatorCalls;
    const int maxFloors = 32;
public:
    ElevatorUsecase() {};
    ~ElevatorUsecase() {};
    void AddElevator(std::string& id, float& maxWeight);
    void Status(std::string& id);
    void CallElevator(std::string& id, int& floor);
    void EnterElevator(std::string& id, float& totalWeightIn, int& fromFloor, int& toFloor);
    void ExitElevator(std::string& id, float& totalWeightOut);
    void Continue(std::string& id);
};
