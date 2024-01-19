#include "Header.h"
//TODO add input handler with variable input fitting to selected function
int main()
{
	string userInputString;
	int userInputNumber = {};
	//Add class functions to a vector to call descriptions and functions more easily later
	vector<unique_ptr<BaseFunction>> functions;
	functions.push_back(make_unique<ReverseStr>());
	functions.push_back(make_unique<RemoveSpaces>());
	functions.push_back(make_unique<Lotto>());
	functions.push_back(make_unique<TicTacToe>());

	while (true) {
		cout << "Choose a function(0,1,2...) or type 'q' to quit.\n";
		for (int i = 0; i < functions.size(); i++)
			cout << i << ". " << functions[i]->getName() << '\n';
		cin >> userInputString;
		if (userInputString == "q") {
			break;
		}
		//Check for right input
		while (true) {
			istringstream iss(userInputString);
			if (iss >> userInputNumber && userInputNumber <= functions.size() - 1) {
				break;
			}
			else {
				cout << "Please enter a number to choose function\n";
			}
			cin >> userInputString;
		}
		//Print out functions and tell which parameters are needed
		vector<pair<string, string>> parameters = extractParameters(functions[userInputNumber]->getName());
		cout << "Enter " << parameters.size() << " parameter(s) for " << functions[userInputNumber]->getName() << " to manipulate : ";

		cin.ignore(); // Clear any remaining characters from the previous input
		getline(cin, userInputString);

		//Count process duration and start process
		auto startTime = high_resolution_clock::now();
		if (functions.size() >= userInputNumber)
			cout << functions[userInputNumber]->execute(userInputString) << '\n';

		auto endTime = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(endTime - startTime).count();
		auto minute = duration_cast<minutes>(endTime - startTime).count();
		auto remainingMicroseconds = duration % 1000000;
		cout << " Time taken by function: " << minute << " minutes " << remainingMicroseconds << " microseconds\n" << endl;
	}
	cout << "Quitting app" << endl;
}

