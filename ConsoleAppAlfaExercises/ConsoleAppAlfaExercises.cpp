#include "Header.h"

//TODO add input handler with variable input, only ask for input after function is selected
template<typename T>
using FuncStrPtr = function<void(const T)>;



int main()
{
	string userInputString;
	double userInputNumber;
	string command;

	vector<unique_ptr<BaseFunction>> functions;
	functions.push_back(make_unique<ReverseStr>());

	while (true) {
		cout << "Choose a function(0,1,2...) (or type 'q' to quit).'\n' ";
		for (int i = 0; i < functions.size(); i++)
			cout << i << ". " << functions[i]->getName() << '\n';
		
		//getline(cin, userInputString);
		cin >> userInputString;
		if (userInputString == "q") {
			break;
		}
		istringstream iss(userInputString);
		if (iss >> userInputNumber) {
			cout << "Entered number: " << userInputNumber << '\n';
		}
		else {
			cout << "Entered string: " << userInputString << '\n';
		}
		cout << "Enter string to manipulate: ";
		cin >> userInputString;
		auto startTime = chrono::high_resolution_clock::now();
		
		if (functions.size() >= userInputNumber) {
			cout << '\n' << functions[userInputNumber]->execute(userInputString);
		}

		/*cout << reverseString(userInputString) << '\n';
		cout << removeSpaces(userInputString) << '\n';
		cout << countNumsInString(userInputString) << '\n';
		cout << removeLeadingSpaces(userInputString) << '\n';
		cout << removeTrailingSpaces(userInputString) << '\n';*/

		auto endTime = chrono::high_resolution_clock::now();

		auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
		iss = {};
		userInputString = {};
		userInputNumber = {};
		cout << " Time taken by function: " << duration << " microseconds\n";
	}

	cout << "Quitting app" << endl;

}

