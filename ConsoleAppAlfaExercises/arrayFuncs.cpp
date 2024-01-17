#include "Header.h"

string Lotto::execute(string& x) {
	srand(static_cast<unsigned int>(time(nullptr)));
	int a, b, c, d, e, f, trys = {};
	cout << "Enter 6 numbers for Lotto between 1 and 49 (separated by spaces): ";
	cin >> a >> b >> c >> d >> e >> f;
	vector<int> targetNumbers = {a,b,c,d,e,f};
	set<int> generatedNumbers;
	cout << "Choosen Numbers: ";
	for (int number : targetNumbers) {
		cout << number << " ";
	}
	cout << endl;
	do {
		generatedNumbers.clear(); // Clear the previous set of numbers

		// Generate 6 random numbers
		for (int i = 0; i < 6; ++i) {
			int randomNumber;
			do {
				randomNumber = rand() % 49 + 1; // Get a random number
			} while (!generatedNumbers.insert(randomNumber).second);
		}
		trys++;
		// Output the generated numbers in-place
	/*	cout << "Generated Numbers: ";
		for (int number : generatedNumbers) {
			cout << setw(2) << number << " ";
		}
		cout << '\r' << flush; // Carriage return and flush to update output in-place*/
	} while (generatedNumbers.size() != targetNumbers.size() || !equal(generatedNumbers.begin(), generatedNumbers.end(), targetNumbers.begin()));
	// Output the generated numbers
	cout << "Generated Numbers and tickets: ";
	for (int number : generatedNumbers) {
		cout << number << " ";
	}
	cout << endl;
	cout << trys << endl;
	cout << "Match found! The generated numbers match the target numbers." << endl;
	return "";
}
string Lotto::getName() const {
	return "jackpotKnacker(int a, int b, int c, int d, int e, int f)";
}

unique_ptr<int[]> createArray(int a) {
	unique_ptr<int[]> dynamicArray = make_unique<int[]>(a);
	return dynamicArray;
}


unique_ptr<int[]> fillArray(unique_ptr<int[]> a) {
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		a[i] = i;
	}
	return a;
}

void printArray(unique_ptr<int[]> a) {
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		cout << a[i] << '\n';
	}
}