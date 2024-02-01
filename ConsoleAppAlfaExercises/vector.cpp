#include "Header.h"

std::string VectorAlloc::Execute(std::string& a) {
    return "";
}
std::string VectorAlloc::Execute(std::vector<double>& userVector) {
    try {
        std::vector<int> intArray(userVector.at(0));  
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Error: Unable to allocate memory - " << e.what() << "\n";
    }
    return "";
}

std::string Vector::Execute(std::string& a) {
    return "";
}

std::string Vector::Execute(std::vector<double>& userVector) {
    std::vector<double> method1 = { 1.0, 2.5, 3.7, 4.2 };

    std::cout << "Method 1: Initialization with explicit values" << std::endl;
    for (double value : method1) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::vector<double> method2(5);

    std::cout << "Method 2: Initialization with a specific number of elements (default value: 0.0)" << std::endl;
    for (double value : method2) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::vector<double> method3;
    method3.push_back(2.0);
    method3.push_back(4.5);
    method3.push_back(6.3);

    std::cout << "Method 3: Using push_back" << std::endl;
    for (double value : method3) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return "";
}

std::string VectorMinMax::Execute(std::string& a) {
    return "";
}

std::string VectorMinMax::Execute(std::vector<double>& userVector) {
    if (userVector.empty()) {
        // If the vector is empty, return a pair with both values as NaN.
        std::pair<double, double> result = { std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN() };
        std::cout << "User Vector - Min: " << result.first << ", Max: " << result.second << std::endl;
        return "Vector empty";
    }

    double minVal = *std::min_element(userVector.begin(), userVector.end());
    double maxVal = *std::max_element(userVector.begin(), userVector.end());

    std::pair<double, double> result = { minVal, maxVal };
    std::cout << "User Vector - Min: " << result.first << ", Max: " << result.second << std::endl;
    return "";
}

std::string VectorReverse::Execute(std::string& a) {
    return "";
}

std::string VectorReverse::Execute(std::vector<double>& userVector) {
    std::cout << "Original Vector: ";
    for (double value : userVector) {
        std::cout << value << " ";
    }
    std::vector<double> reversedVector;

    if (userVector.empty()) {
        std::cout << "Vector is empty." << std::endl;
        return "";
    }

    for (auto it = userVector.rbegin(); it != userVector.rend(); ++it) {
        reversedVector.push_back(*it);
    }
    std::cout << "Reversed Vector: ";
    for (double value : reversedVector) {
        std::cout << value << " ";
    }
    return "";
}

std::string VectorRound::Execute(std::string& a) {
    return "";
}

std::string VectorRound::Execute(std::vector<double>& userVector) {
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
