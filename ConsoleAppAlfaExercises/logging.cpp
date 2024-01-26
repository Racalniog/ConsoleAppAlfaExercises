#include "Header.h"

// Function to log current time and message to a file WIP

// Function to get the current timestamp as a string
std::string GetCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::tm tm_struct;
    localtime_s(&tm_struct, &now_c);

    std::ostringstream oss;
    oss << std::put_time(&tm_struct, "%Y-%m-%d %X");
    return oss.str();
}


template <typename... Args>
void LogOutput(Args&&... args) {
    std::ostringstream oss;
    oss << GetCurrentTimestamp() << " ";
    (oss << ... << std::forward<Args>(args));

    std::cout << oss.str();
    logFile << oss.str();
}

void LogInput(std::string& input) {
    std::getline(std::cin, input);
    logFile << GetCurrentTimestamp() << " Input: " << input << std::endl;
}

//int main() {
//    std::string userInput;
//
//    // Some program logic and output
//    logOutput("write in file\n");
//
//    // Read from the console
//    logOutput("Enter some input: ");
//    logInput(userInput);
//
//    // Additional example with multiple parameters
//    int x = 42;
//    logOutput("Value of x: ", x, " test");
//
//    return 0;
//}
