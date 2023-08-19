#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include "elevatorUsecase.h"
#include "utils.h"

int main()
{
    std::cout << "List of commands: " << "\n";
    std::cout << "<add-elevator <elevator-id> <max-weight-supported>> this command will add an Elevator" << "\n";
    std::cout << "<status <elevator-id>> this command will show information about the an elevator" << "\n";
    std::cout << "<call-elevator <elevator-id> <floor-name>> this command will call an Elevator to specified floor" << "\n";
    std::cout << "<enter-elevator <elevator-id> <total-weight-entering> <space-between-floors>> this command will enter an specified Elevator" << "\n";
    std::cout << "<exit-elevator <elevator-id> <weight-exiting>> this command will exit from an specified Elevator" << "\n";
    std::cout << "<continue <elevator-id>> this command will keep an Elevator moving" << "\n\n";

    std::string userInput{ "" };

    ElevatorUsecase usecase;

    while (std::getline(std::cin, userInput)) {
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
                    stream >> maxWeight;
                    usecase.AddElevator(elevatorId, maxWeight);
                }
                else if (command == statusCommand) {
                    usecase.GetElevatorStatus(elevatorId);
                }
                else if (command == callCommand) {
                    int floor;
                    usecase.CallElevator(elevatorId, floor);
                }
                else if (command == enterCommand) {
                    float enteringWeight;
                    int toFloor;
                    stream >> enteringWeight >> toFloor;
                    usecase.EnterElevator(elevatorId, enteringWeight, toFloor);
                }
                else if (command == exitCommand) {
                    float exitingWeight;
                    stream >> exitingWeight;
                    usecase.ExitElevator(elevatorId, exitingWeight);
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

        std::transform(userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c) { return std::tolower(c); });
        if (userInput == "exit")
        {
            break;
        }
    }
    return 0;
}