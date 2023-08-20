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
    Elevator elevator = elevators[id];
    if (!elevator.IsMoving())
    {
        std::cout << "status " << id << "-> stationary " << elevator.GetCurrentFloor()
            << " current Weight " << elevator.GetCurrentWeight() << "\n";
        return;
    }
    if (elevator.GetPreviousFloor() < elevatorCalls[id].front())
    {
        std::cout << "status " << id << "-> moving up " << elevator.GetPreviousFloor()
            << " to " << elevatorCalls[id].front() << "\n";
    }
    else {
        std::cout << "status " << id << "-> moving down " << elevator.GetPreviousFloor()
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

void ElevatorUsecase::EnterElevator(std::string& id, float& totalWeightIn, int& fromFloor, int& toFloor) {
    if (elevators.find(id) == elevators.end())
    {
        std::cout << "Failure->Elevator doesnt exists" << "\n";
        return;
    }
    Elevator elevator = elevators[id];
    if (elevator.GetCurrentFloor() != fromFloor)
    {
        std::cout << "Failure->Elevator isnt in your floor" << "\n";
        return;
    }
    if ((totalWeightIn + elevator.GetCurrentWeight()) > elevator.GetMaxWeight())
    {
        std::cout << "Failure->Elevator is exceding its max weight" << "\n";
        return;
    }

    if (elevator.GetCurrentFloor() == fromFloor) {
        elevators[id].AddCurrentWeight(totalWeightIn);
        elevatorCalls[id].pop_front();
        elevatorCalls[id].emplace_back(toFloor);
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
    Elevator* elevator = &elevators[id];
    if (elevator->GetCurrentWeight() <= 0) {
        std::cout << "Failure->Elevator is empty" << "\n";
        return;
    }
    elevator->RemoveCurrentWeight(totalWeightOut);
    std::cout << "Success->Exit Elevator with " << totalWeightOut << " weight" << "\n";
    elevator = nullptr;
}

void ElevatorUsecase::Continue(std::string& id) {
    if (elevators.find(id) == elevators.end())
    {
        std::cout << "Failure->Elevator doesnt exists" << "\n";
        return;
    }
    int nextFloorToStop = elevatorCalls[id].front();
    Elevator* elevator = &elevators[id];

    elevator->SetPreviousFloor(elevator->GetCurrentFloor());
    while (true) {
        if (elevator->GetCurrentFloor() == nextFloorToStop)
        {
            elevator->StopMoving();
            break;
        }
        if (elevator->GetCurrentFloor() > nextFloorToStop)
        {
            elevator->MovingDown();
        }
        else {
            elevator->MovingUp();
        }
    }
    std::cout << "Continue " << id << "\n";
    elevator = nullptr;
}