#include "Header.h"

// TODO: Anagram generator
std::string ReverseStr::Execute(std::vector<double>& userVector) {
    return "";
}

std::string ReverseStr::Execute(std::string& a) {
    std::reverse(a.begin(), a.end());
    return a;
}

std::string RemoveSpaces::Execute(std::vector<double>& userVector) {
    return "";
}

std::string RemoveSpaces::Execute(std::string& a) {
    a.erase(std::remove_if(a.begin(), a.end(), [](char c) { return std::isspace(c); }), a.end());
    return a;
}

std::string CountNumsInString::Execute(std::vector<double>& userVector) {
    return "";
}

std::string CountNumsInString::Execute(std::string& a) {
    int nums = 0;
    for (char c : a) {
        if (std::isdigit(c))
            nums++;
    }
    std::cout << nums;
    return "";
}

std::string Palindrome::Execute(std::vector<double>& userVector) {
    return "";
}

std::string Palindrome::Execute(std::string& str) {
    std::string cleanedStr;

    // Remove non-alphanumeric characters and convert to lowercase
    for (char ch : str) {
        if (iswalnum(ch)) {
            cleanedStr += std::tolower(ch);
        }
    }

    // Check if the cleaned string is a palindrome
    for (size_t i = 0; i < cleanedStr.length() / 2; ++i) {
        if (cleanedStr[i] != cleanedStr[cleanedStr.length() - 1 - i]) {
            return "false";
        }
    }

    return "true";
}

std::string RemoveLeadingSpaces::Execute(std::vector<double>& userVector) {
    return "";
}

std::string RemoveLeadingSpaces::Execute(std::string& a) {
    a.erase(a.begin(), std::find_if_not(a.begin(), a.end(), [](char c) { return std::isspace(c); }));
    return a;
}

std::string RemoveTrailingSpaces::Execute(std::vector<double>& userVector) {
    return "";
}

std::string RemoveTrailingSpaces::Execute(std::string& a) {
    a.erase(std::find_if_not(a.rbegin(), a.rend(), [](char c) { return std::isspace(c); }).base(), a.end());
    return a;
}

std::vector<std::pair<std::string, std::string>> ExtractParameters(const std::string& functionSignature) {
    std::vector<std::pair<std::string, std::string>> parameters;

    // Define a regular expression pattern to match parameter types and names
    std::regex pattern(R"((\w+)\s+(\w+))");

    // Use regex_iterator to iterate over matches in the function signature
    auto it = std::sregex_iterator(functionSignature.begin(), functionSignature.end(), pattern);
    auto end = std::sregex_iterator();

    for (; it != end; ++it) {
        // Extract matched parameter type and name
        std::smatch match = *it;
        if (match.size() == 3) { // Assuming two capturing groups (type and name)
            parameters.emplace_back(match[1], match[2]);
        }
    }

    return parameters;
}
