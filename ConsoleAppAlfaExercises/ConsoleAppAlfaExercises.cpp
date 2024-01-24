#include "Header.h"
//TODO add input handler with variable input fitting to selected function
int main()
{
	string userInputString;
	int userInputNumber = {}; 
	//Added class functions to a vector to call descriptions and functions more easily
	vector<unique_ptr<BaseFunction>> functions;

	functions.push_back(make_unique<ReverseStr>());
	functions.push_back(make_unique<RemoveSpaces>());
	functions.push_back(make_unique<CountNumsInString>());
	functions.push_back(make_unique<RemoveLeadingSpaces>());
	functions.push_back(make_unique<RemoveTrailingSpaces>());
	functions.push_back(make_unique<Lotto>());
	functions.push_back(make_unique<TicTacToe>());
	functions.push_back(make_unique<Palindrome>());
	functions.push_back(make_unique<Vector>());
	functions.push_back(make_unique<VectorMinMax>());
	functions.push_back(make_unique<VectorReverse>());
	functions.push_back(make_unique<VectorRound>());


	while (true) {
		cout << "Choose a function(0,1,2...) or type 'q' to quit.\n";
		for (int i = 0; i < functions.size(); i++) {
			cout << i << ". " << functions[i]->getName() << '\t';
			if (i % 2 == 0 && i >1)
				cout << '\n';
		}
		cout << '\n';
		getline(cin, userInputString);

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
			getline(cin, userInputString);
		}
		//Print out function and tell which parameters are needed
		vector<pair<string, string>> parameters = extractParameters(functions[userInputNumber]->getName());
		cout << "Enter " << parameters.size() << " parameter(s) for " << functions[userInputNumber]->getName() << " to manipulate : ";
		// Check if the parameter types include "std::string"
		bool hasStringParameter = false;
		for (const auto& param : parameters) {
			if (param.first == "string") {
				hasStringParameter = true;
				break;
			}
		}
		auto startTime = high_resolution_clock::now();
		// Call the function based on the detected parameter types
		if (hasStringParameter && functions.size() >= userInputNumber) {
			// Call the function to handle string input
			getline(cin, userInputString);
			auto result = functions[userInputNumber]->execute(userInputString);
			for (auto x : result)
			{
				cout << x;
			}
		}
		else if(!hasStringParameter && functions.size() >= userInputNumber){
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
			auto result = functions[userInputNumber]->execute(inputVec);
			for (auto x : result)
			{
				cout << x << " ";
			}
		}
		auto endTime = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(endTime - startTime).count();
		auto minute = duration_cast<minutes>(endTime - startTime).count();
		auto remainingMicroseconds = duration % 1000000;
		cout << "\n Time taken by function: " << minute << " minutes " << remainingMicroseconds << " microseconds\n" << endl;
	}
	cout << "Quitting app" << endl;
}

