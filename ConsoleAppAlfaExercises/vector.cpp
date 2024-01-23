#include "Header.h"

string Vector::execute(string& a) {
    // Methode 1: Initialisierung mit expliziten Werten
    std::vector<double> method1 = { 1.0, 2.5, 3.7, 4.2 };

    std::cout << "Method 1:" << std::endl;
    for (double value : method1) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Methode 2: Initialisierung mit einer bestimmten Anzahl an Elementen (Standardwert: 0.0)
    std::vector<double> method2(5);

    std::cout << "Method 2:" << std::endl;
    for (double value : method2) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Methode 3: Verwenden von push_back
    std::vector<double> method3;
    method3.push_back(2.0);
    method3.push_back(4.5);
    method3.push_back(6.3);

    std::cout << "Method 3:" << std::endl;
    for (double value : method3) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
	return "";
}
string Vector::execute(vector<double> userVector) {
    return"";
}
string VectorMinMax::execute(string& a) {
    return "";
}
string VectorMinMax::execute(vector<double> userVector) {
    if (userVector.empty()) {
        // Wenn der Vektor leer ist, gib ein Paar mit beiden Werten als NaN zurück.
        pair<double, double> result = std::make_pair(std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN());
        std::cout << "User Vector - Min: " << result.first << ", Max: " << result.second << std::endl;
        return "Vector empty";
    }

    double minVal = *std::min_element(userVector.begin(), userVector.end());
    double maxVal = *std::max_element(userVector.begin(), userVector.end());

    pair<double, double> result = std::make_pair(minVal, maxVal);
    std::cout << "User Vector - Min: " << result.first << ", Max: " << result.second << std::endl;
    return "";
}

string VectorReverse::execute(string& a) {
    std::cout << "Enter numbers separated by spaces (enter f to finish): ";
    std::vector<double> userVector;
    double input;

    while (std::cin >> input) {
        // Successfully read a double
        userVector.push_back(input);
    }
    // Check for the end-of-file condition
    if (std::cin.eof()) {
        // End of input reached
        std::cout << "End of input reached." << std::endl;
    }
    else {
        // Input was not a valid double
        std::cout << "Detected letter input. Stopping user input." << std::endl;
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }

    std::cout << "Original Vector: ";
    for (double value : userVector) {
        std::cout << value << " ";
    }
    std::vector<double> reversedVector;

    // Überprüfen, ob der Eingabevektor leer ist
    if (userVector.empty()) {
        std::cout << "Vector is empty." << std::endl;
        return "";
    }

    // Kopieren der Elemente in umgekehrter Reihenfolge
    for (auto it = userVector.rbegin(); it != userVector.rend(); ++it) {
        reversedVector.push_back(*it);
    }
    std::cout << "Reversed Vector: ";
    for (double value : reversedVector) {
        std::cout << value << " ";
    }
    return "";
}
string VectorReverse::execute(vector<double> userVector) {
    return"";
}
string VectorRound::execute(string& a) {
    std::cout << "Enter numbers separated by spaces (enter f to finish): ";
    std::vector<double> userVector;
    double input;
    std::vector<double> roundedVector;

    while (std::cin >> input) {
        // Successfully read a double
        userVector.push_back(input);
    }
    // Check for the end-of-file condition
    if (std::cin.eof()) {
        // End of input reached
        std::cout << "End of input reached." << std::endl;
    }
    else {
        // Input was not a valid double
        std::cout << "Detected letter input. Stopping user input." << std::endl;
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }

    std::cout << "Original Vector: ";
    for (double value : userVector) {
        std::cout << value << " ";
    }

    for (double& value : userVector) {
        value = std::round(value);
    }

    std::cout << "Rounded Vector: ";
    for (double value : userVector) {
        std::cout << value << " ";
    }
    return "";
}
string VectorRound::execute(vector<double> userVector) {
    return"";
}