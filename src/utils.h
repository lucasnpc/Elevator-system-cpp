#include <string>
#include <algorithm>

static const std::string addCommand = "add-elevator";
static const std::string statusCommand = "status";
static const std::string callCommand = "call-elevator";
static const std::string enterCommand = "enter-elevator";
static const std::string exitCommand = "exit-elevator";
static const std::string continueCommand = "continue";

bool isUserInputValid(std::string input) {
    input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
    for (char c : input) {
        if (!isalnum(c) && c != '-') {
            return false;
        }
    }
    return true;
}