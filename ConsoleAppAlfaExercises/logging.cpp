#include "Header.h"

std::string GetCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::tm tm_struct;
    localtime_s(&tm_struct, &now_c);

    std::ostringstream oss;
    oss << std::put_time(&tm_struct, "%Y-%m-%d %X");
    return oss.str();
}

void LogInput(std::string& input) {
    std::getline(std::cin, input);
    logFile << GetCurrentTimestamp() << " Input: " << input << std::endl;
}
