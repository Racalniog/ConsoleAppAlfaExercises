#include "Header.h"

//TODO add input handler with variable input(template), switch case for different functions, only ask for input after function is selected
int main()
{
    string userInputString;
    double userInputNumber;
    string command;

    while (true) {
        cout << "Enter a string (or type 'q' to quit): ";
        getline(cin, userInputString);

        if (userInputString == "q") {
            break;
        }
        unique_ptr<int[]> dynArray;
        cout << "Enter a number: ";
        cin >> userInputNumber;
        cin.ignore(); // ignore newline in buffer

        auto startTime = chrono::high_resolution_clock::now();

        dynArray = createArray(userInputNumber);

        cout << dynArray[1] << '\n';

        auto endTime = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

        cout << " Time taken by function: " << duration << " microseconds\n";
    }

    cout << "Quitting app" << endl;

}

