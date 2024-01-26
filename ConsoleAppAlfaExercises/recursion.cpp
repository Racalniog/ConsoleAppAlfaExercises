#include "Header.h"


std::string Rekursion::GetName() {
	return "fibN(int i)";
}

size_t fibonacciRecursive(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }
}
std::string Rekursion::Execute(std::string& x) {
    return "";
}
std::string Rekursion::Execute(std::vector<double>& x) {
    std::cout << fibonacciRecursive(static_cast<int> (x[0]));

	return "";
}