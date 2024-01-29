#include "Header.h"

/*  
TODO: Clean code, fix time taking, and logging
Fit input better to all exceptional functions!
*/
std::ofstream logFile("log.txt", std::ios::out | std::ios::app);

int main() {
    std::string userInputString;
    int userInputNumber = {};

    // Added class functions to a vector to call descriptions and functions more easily
    std::vector<std::unique_ptr<BaseFunction>> functions;
    functions.emplace_back(std::make_unique<ReverseStr>());
    functions.emplace_back(std::make_unique<RemoveSpaces>());
    functions.emplace_back(std::make_unique<CountNumsInString>());
    functions.emplace_back(std::make_unique<RemoveLeadingSpaces>());
    functions.emplace_back(std::make_unique<RemoveTrailingSpaces>());
    functions.emplace_back(std::make_unique<Lotto>());
    functions.emplace_back(std::make_unique<TicTacToe>());
    functions.emplace_back(std::make_unique<Palindrome>());
    functions.emplace_back(std::make_unique<Vector>());
    functions.emplace_back(std::make_unique<VectorMinMax>());
    functions.emplace_back(std::make_unique<VectorReverse>());
    functions.emplace_back(std::make_unique<VectorRound>());
    functions.emplace_back(std::make_unique<Rekursion>());
    functions.emplace_back(std::make_unique<Becher>());
    functions.emplace_back(std::make_unique<BecherAufdruck>());


    while (true) {
        std::cout << "Choose a function (0, 1, 2...) or type 'q' to quit.\n";
        for (int i = 0; i < functions.size(); i++) {
            std::cout << i << ". " << functions[i]->GetName() << '\t';
            if (i % 2 == 0 && i > 1)
                std::cout << '\n';
        }
        std::cout << '\n';

        getline(std::cin, userInputString);
        if (userInputString == "q") {
            break;
        }

        // Check for the right input
        while (true) {
            std::istringstream iss(userInputString);
            if (iss >> userInputNumber && userInputNumber <= functions.size() - 1) {
                break;
            }
            else {
                std::cout << "Please enter a number to choose a function.\n";
            }
            getline(std::cin, userInputString);
        }

        // Print out function and tell which parameters are needed
        std::vector<std::pair<std::string, std::string>> parameters = ExtractParameters(functions[userInputNumber]->GetName());
        std::cout << "Enter " << parameters.size() << " parameter(s) for " << functions[userInputNumber]->GetName() << " to manipulate: ";

        // Check if the parameter types include "string"
        bool hasStringParameter = false;
        for (const auto& param : parameters) {
            if (param.first == "string") {
                hasStringParameter = true;
                break;
            }
        }

        auto startTime = std::chrono::high_resolution_clock::now();

        // Call the function based on the detected parameter types
        if (hasStringParameter && functions.size() >= userInputNumber) {
            // Call the function to handle string input
            getline(std::cin, userInputString);
            auto result = functions[userInputNumber]->Execute(userInputString);
            for (const auto& x : result) {
                std::cout << x;
            }
        }
        else if (!hasStringParameter && functions.size() >= userInputNumber) {
            // Assuming no "string" parameters, process vector input
            std::vector<double> inputVec;
            std::cout << "Enter numbers separated by space: ";
            std::string line;
            std::getline(std::cin, line);
            std::istringstream iss(line);
            double num;
            while (iss >> num) {
                inputVec.push_back(num);
            }

            // Call the function to handle vector input
            auto result = functions[userInputNumber]->Execute(inputVec);
            for (const auto& x : result) {
                std::cout << x << " ";
            }
        }

        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
        auto minute = std::chrono::duration_cast<std::chrono::minutes>(endTime - startTime).count();
        auto remainingMicroseconds = duration % 1000000;
        std::cout << "\n Time taken by function: " << minute << " minutes " << remainingMicroseconds << " microseconds\n" << std::endl;
    }

    std::cout << "Quitting app" << std::endl;
}
