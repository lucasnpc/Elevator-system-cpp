#include "elevator.h"
#include <map>
#include <string>


class ElevatorUsecase
{
    std::map<std::string, Elevator> elevators;
    const int maxFloors = 32;
public:
    ElevatorUsecase();
    ~ElevatorUsecase();
    void AddElevator(std::string& elevatorId, float& maxWeight);
    void GetElevatorStatus(std::string& elevatorId);
    void CallElevator(std::string& elevatorId, int& floor);
    void EnterElevator(std::string& elevatorId, float& totalWeightIn, int& floorTo);
    void ExitElevator(std::string& elevatorId, float& totalWeightOut);
    void Continue(std::string& elevatorId);
};
