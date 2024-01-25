#include "Header.h"

string Lotto::execute(string& a) {
	return "";
}
string Lotto::execute(vector<double>& userVector) {
	std::cout << "Choosen Numbers: ";
	sort(userVector.begin(), userVector.end());
	for (auto number : userVector) {
		std::cout << number << " ";
	}
	std::cout << endl;
	std::thread lottoThread(&Lotto::generateLottoNumbers, this, userVector);

	lottoThread.join(); // Wait for the lottoThread to finish	
	return"";
}
void Lotto::generateLottoNumbers(const std::vector<double>& targetNumbers) {
	srand(static_cast<unsigned int>(time(nullptr)));
	int trys = 0;
	std::set<int> generatedNumbers;

	do {
		generatedNumbers.clear(); // Clear the previous set of numbers

		// Generate 6 random numbers
		for (int i = 0; i < 6; ++i) {
			int randomNumber;
			do {
				randomNumber = rand() % 49 + 1; // Get a random number
			} while (!generatedNumbers.insert(randomNumber).second); // check if generated number is in the set
		}

		trys++;
	} while (generatedNumbers.size() != targetNumbers.size() || !std::equal(generatedNumbers.begin(), generatedNumbers.end(), targetNumbers.begin()));

	// Output the generated numbers
	std::cout << "Generated Numbers and tickets: ";
	for (int number : generatedNumbers) {
		std::cout << number << " ";
	}
	std::cout << std::endl;

	std::cout << trys << std::endl;
	std::cout << "Match found! The generated numbers match the target numbers." << std::endl;
}
string Lotto::getName() {
	return "jackpotCracker(int a, int b, int c, int d, int e, int f)";
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
		std::cout << a[i] << '\n';
	}
}