#include <string>

static const std::string addCommand = "add";
static const std::string statusCommand = "status";
static const std::string callCommand = "call";
static const std::string enterCommand = "enter";
static const std::string leaveCommand = "leave";
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