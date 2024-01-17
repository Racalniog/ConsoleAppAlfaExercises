#include "Header.h"
//TODO add input handler with variable input, only ask for input after function is selected
int main()
{
	string userInputString;
	double userInputNumber = {};
	vector<unique_ptr<BaseFunction>> functions;
	functions.push_back(make_unique<ReverseStr>());

	while (true) {
		cout << "Choose a function(0,1,2...) (or type 'q' to quit).'\n' ";
		for (int i = 0; i < functions.size(); i++)
			cout << i << ". " << functions[i]->getName() << '\n';
		cin >> userInputString;
		if (userInputString == "q") {
			break;
		}
		while (true) {
			istringstream iss(userInputString);
			if (iss >> userInputNumber && userInputNumber <= functions.size()-1) {
				cout << "Entered number: " << userInputNumber << '\n';
				break;
			}
			else {
				cout << "Please enter a number to choose function\n";
			}
			cin >> userInputString;
		}
		cout << "Enter string to manipulate: ";
		cin >> userInputString;
		auto startTime = chrono::high_resolution_clock::now();
		
		if (functions.size() >= userInputNumber) {
			cout << functions[userInputNumber]->execute(userInputString) << '\n';
		}

		auto endTime = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
		cout << " Time taken by function: " << duration << " microseconds" << endl;
	}
	cout << "Quitting app" << endl;
}

