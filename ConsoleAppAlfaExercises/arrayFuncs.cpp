#include "Header.h"

std::string Lotto::Execute(std::string& a) {
    return "";
}

std::string Lotto::Execute(std::vector<double>& userVector) {
    std::cout << "Chosen Numbers: ";
    std::sort(userVector.begin(), userVector.end());

    for (const auto& number : userVector) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    std::thread lottoThread(&Lotto::GenerateLottoNumbers, this, userVector);
    lottoThread.join(); // Wait for the lottoThread to finish

    return "";
}

void Lotto::GenerateLottoNumbers(const std::vector<double>& targetNumbers) {
    srand(static_cast<unsigned int>(time(nullptr)));
    int tries = 0;
    std::set<int> generatedNumbers;

    do {
        generatedNumbers.clear(); // Clear the previous set of numbers

        // Generate 6 random numbers
        for (int i = 0; i < 6; ++i) {
            int randomNumber;
            do {
                randomNumber = rand() % 49 + 1; // Get a random number
            } while (!generatedNumbers.insert(randomNumber).second); // Check if generated number is in the set
        }

        tries++;
    } while (generatedNumbers.size() != targetNumbers.size() || !std::equal(generatedNumbers.begin(), generatedNumbers.end(), targetNumbers.begin()));

    // Output the generated numbers
    std::cout << "Generated Numbers and tickets: ";
    for (int number : generatedNumbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    std::cout << tries << std::endl;
    std::cout << "Match found! The generated numbers match the target numbers." << std::endl;
}

std::string Lotto::GetName() {
    return "jackpotCracker(int a, int b, int c, int d, int e, int f)";
}

std::unique_ptr<int[]> CreateArray(int a) {
    std::unique_ptr<int[]> dynamicArray = std::make_unique<int[]>(a);
    return dynamicArray;
}

std::unique_ptr<int[]> FillArray(std::unique_ptr<int[]>& a, int size) {
    std::unique_ptr<int[]> b;
    for (int i = 0; i < size; i++) {
        b[i] = i;
    }
    return b;
}

void PrintArray(const std::unique_ptr<int[]>& a, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << a[i] << '\n';
    }
}
