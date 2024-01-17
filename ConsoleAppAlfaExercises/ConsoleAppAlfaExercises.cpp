#include "Header.h"

//TODO add input handler with variable input(template), map data structure for mapping user choices to functions, only ask for input after function is selected
template<typename T>
using FuncStrPtr = function<void(const T)>;



int main()
{
	string userInputString;
	double userInputNumber;
	string command;

	vector<unique_ptr<BaseFunction>> functions;
	functions.push_back(make_unique<ReverseStr>());

	//map<int, std::any> functionMap;


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

		//dynArray = createArray(userInputNumber);

		for (const auto& func : functions) {
			cout << func->execute(userInputString) << '\n';
			cout << func->getName() << '\n';

		}

		cout << reverseString(userInputString) << '\n';
		cout << removeSpaces(userInputString) << '\n';
		cout << countNumsInString(userInputString) << '\n';
		cout << removeLeadingSpaces(userInputString) << '\n';
		cout << removeTrailingSpaces(userInputString) << '\n';

		auto endTime = chrono::high_resolution_clock::now();

		auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

		cout << " Time taken by function: " << duration << " microseconds\n";
	}

	cout << "Quitting app" << endl;

}

