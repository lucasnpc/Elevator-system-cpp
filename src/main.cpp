#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include "elevatorUsecase.h"
#include "utils.h"

int main()
{
    std::cout << "List of commands: " << "\n\n";
    std::cout << "<add <elevator-id> <max-weight-supported>> this command will add an Elevator" << "\n";
    std::cout << "<status <elevator-id>> this command will show information about the an elevator" << "\n";
    std::cout << "<call <elevator-id> <floor-name>> this command will call an Elevator to specified floor" << "\n";
    std::cout << "<enter <elevator-id> <total-weight-entering> <from-floor> <to-floor>> this command will enter an specified Elevator" << "\n";
    std::cout << "<leave <elevator-id> <weight-exiting>> this command will exit from an specified Elevator" << "\n";
    std::cout << "<continue <elevator-id>> this command will keep an Elevator moving" << "\n\n";
    std::cout << "<exit> this command will finish the app" << "\n\n";

    std::string userInput{ "" };

    ElevatorUsecase usecase;

    while (std::getline(std::cin, userInput)) {
        std::transform(userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c) { return std::tolower(c); });
        if (userInput == "exit")
        {
            break;
        }
        if (!isUserInputValid(userInput))
        {
            std::cout << "Enter an valid input" << "\n";
            std::cin.clear();
        }
        else {
            std::istringstream stream(userInput);
            std::string command, elevatorId;
            if (stream >> command >> elevatorId)
            {
                if (command == addCommand)
                {
                    float maxWeight;
                    if (stream >> maxWeight)
                    {
                        usecase.AddElevator(elevatorId, maxWeight);
                    }
                    else {
                        std::cout << "Failure->Max weight of the elevator missing" << "\n";
                    }
                }
                else if (command == statusCommand) {
                    usecase.Status(elevatorId);
                }
                else if (command == callCommand) {
                    int floor;
                    if (stream >> floor)
                    {
                        usecase.CallElevator(elevatorId, floor);
                    }
                    else {
                        std::cout << "Failure->Floor name missing" << "\n";
                    }
                }
                else if (command == enterCommand) {
                    float enteringWeight;
                    int fromFloor, toFloor;
                    if (stream >> enteringWeight >> fromFloor >> toFloor) {
                        usecase.EnterElevator(elevatorId, enteringWeight, fromFloor, toFloor);
                    }
                    else {
                        std::cout << "Failure->Some parameter of the command is missing" << "\n";
                    }
                }
                else if (command == leaveCommand) {
                    float exitingWeight;
                    if (stream >> exitingWeight)
                    {
                        usecase.ExitElevator(elevatorId, exitingWeight);
                    }
                    else {
                        std::cout << "Failure->Exiting weight missing" << "\n";
                    }
                }
                else if (command == continueCommand) {
                    usecase.Continue(elevatorId);
                }
                else {
                    std::cout << "Invalid command" << "\n";
                }
            }
            else {
                std::cout << "Failed to extract values from the stream." << std::endl;
            }
        }
    }
    return 0;
}