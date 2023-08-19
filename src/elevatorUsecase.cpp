#include "elevatorUsecase.h"
#include <iostream>

void ElevatorUsecase::AddElevator(std::string& id, float& maxWeight) {
    if (elevators.find(id) == elevators.end() && !(elevators.size() > maxFloors))
    {
        elevators.emplace(id, std::move(Elevator(maxWeight)));
        std::cout << "Success->Elevator added to the list" << "\n";
    }
    else {
        std::cout << "Failure->Cant add elevator in the list" << "\n";
    }
}

void ElevatorUsecase::Status(std::string& id) {
    if (elevators.find(id) == elevators.end())
    {
        std::cout << "Failure->Elevator doesnt exists" << "\n";
        return;
    }
    int currentFloor = elevators[id].GetCurrentFloor();
    if (!elevators[id].IsMoving())
    {
        std::cout << "status " << id << "-> stationary " << currentFloor << "\n";
        return;
    }
    if (elevators[id].GetPreviousFloor() < elevatorCalls[id].front())
    {
        std::cout << "status " << id << "-> moving up " << elevators[id].GetPreviousFloor()
            << " to " << elevatorCalls[id].front() << "\n";
    }
    else {
        std::cout << "status " << id << "-> moving down " << elevators[id].GetPreviousFloor()
            << " to " << elevatorCalls[id].front() << "\n";
    }
}

void ElevatorUsecase::CallElevator(std::string& id, int& floor) {
    if (elevators.find(id) == elevators.end())
    {
        std::cout << "Failure->Elevator doesnt exists" << "\n";
        return;
    }
    elevatorCalls[id].emplace_back(floor);
    std::cout << "Success->Call elevator " << floor << "\n";
}

void ElevatorUsecase::EnterElevator(std::string& id, float& totalWeightIn, int& fromFloor) {
    if (elevators.find(id) == elevators.end())
    {
        std::cout << "Failure->Elevator doesnt exists" << "\n";
        return;
    }
    int currentFloor = elevators[id].GetCurrentFloor();
    if (currentFloor != fromFloor)
    {
        std::cout << "Failure->Elevator isnt in your floor" << "\n";
        return;
    }
    if (currentFloor == fromFloor) {
        elevators[id].AddCurrentWeight(totalWeightIn);
        elevatorCalls[id].pop_back();
        std::cout << "Success->Entered in the elevator with " << totalWeightIn << " weight" << "\n";
    }
    else {
        std::cout << "Failure->Cant enter the elevator" << "\n";
    }
}

void ElevatorUsecase::ExitElevator(std::string& id, float& totalWeightOut) {
    if (elevators.find(id) == elevators.end())
    {
        std::cout << "Failure->Elevator doesnt exists" << "\n";
        return;
    }
    elevators[id].RemoveCurrentWeight(totalWeightOut);
    std::cout << "Success->Exit Elevator with " << totalWeightOut << " weight" << "\n";
}

void ElevatorUsecase::Continue(std::string& id) {
    if (elevators.find(id) == elevators.end())
    {
        std::cout << "Failure->Elevator doesnt exists" << "\n";
        return;
    }
    int nextFloorToStop = elevatorCalls[id].front();
    if (elevators[id].GetCurrentFloor() == nextFloorToStop)
    {
        elevators[id].StopMoving();
    }
    elevators[id].SetPreviousFloor(elevators[id].GetCurrentFloor());
    while (elevators[id].GetCurrentFloor() != nextFloorToStop) {
        if (elevators[id].GetCurrentFloor() > nextFloorToStop)
        {
            elevators[id].MovingDown();
        }
        else {
            elevators[id].MovingUp();
        }
    }
    std::cout << "Continue " << id << "\n";
}