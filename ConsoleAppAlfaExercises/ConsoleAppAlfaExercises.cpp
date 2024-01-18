#include "Header.h"
//TODO add input handler with variable input fitting to selected function
int main()
{
	string userInputString;
	int userInputNumber = {};
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
		while (true) {
			istringstream iss(userInputString);
			if (iss >> userInputNumber && userInputNumber <= functions.size()-1) {
				break;
			}
			else {
				cout << "Please enter a number to choose function\n";
			}
			cin >> userInputString;
		}
		vector<pair<string, string>> parameters = extractParameters(functions[userInputNumber]->getName());
		cout << "Enter " << parameters.size() << " parameter(s) for "<< functions[userInputNumber]->getName() << " to manipulate : ";
		
		cin.ignore(); // Clear any remaining characters from the previous input
		getline(cin, userInputString);
		auto startTime = high_resolution_clock::now();
		if (functions.size() >= userInputNumber)
			cout << functions[userInputNumber]->execute(userInputString) << '\n';

		auto duration = duration_cast<microseconds>(high_resolution_clock::now() - startTime).count();
		cout << " Time taken by function: " << duration << " microseconds\n" << endl;
	}
	cout << "Quitting app" << endl;
}

