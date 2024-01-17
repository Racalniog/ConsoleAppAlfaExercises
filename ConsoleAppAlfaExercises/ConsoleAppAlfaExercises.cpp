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
				//cout << "Entered number: " << userInputNumber << '\n';
				break;
			}
			else {
				cout << "Please enter a number to choose function\n";
			}
			cin >> userInputString;
		}
		cout << "Enter parameter(s) for function to manipulate: ";
		cin.ignore(); // Clear any remaining characters from the previous input
		getline(cin, userInputString);
		auto startTime = high_resolution_clock::now();
		
		if (functions.size() >= userInputNumber)
			cout << functions[userInputNumber]->execute(userInputString) << '\n';

		auto duration = duration_cast<microseconds>(high_resolution_clock::now() - startTime).count();
		cout << " Time taken by function: " << duration << " microseconds" << endl;
	}
	cout << "Quitting app" << endl;
}

