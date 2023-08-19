#include "elevatorUsecase.h"
#include <iostream>

ElevatorUsecase::ElevatorUsecase()
{
}

ElevatorUsecase::~ElevatorUsecase()
{
}

void ElevatorUsecase::AddElevator(std::string& elevatorId, float& maxWeight) {
    if (elevators.find(elevatorId) == elevators.end() && !(elevators.size() > maxFloors))
    {
        elevators.emplace(elevatorId, std::move(Elevator(maxWeight)));
        std::cout << "Success->Elevator added to the list" << "\n";
    }
    else {
        std::cout << "Failure->Cant add elevator in the list" << "\n";
    }
}

void ElevatorUsecase::CallElevator(std::string& elevatorId, int& floor) {

}

void ElevatorUsecase::GetElevatorStatus(std::string& elevatorId) {

}

void ElevatorUsecase::EnterElevator(std::string& elevatorId, float& totalWeightIn, int& floorTo) {

}

void ElevatorUsecase::ExitElevator(std::string& elevatorId, float& totalWeightOut) {

}

void ElevatorUsecase::Continue(std::string& elevatorId) {

}