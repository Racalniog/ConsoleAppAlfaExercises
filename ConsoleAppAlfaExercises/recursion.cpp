#include "Header.h"


string Rekursion::getName() {
	return "fibN(int i)";
}

int fibonacciRecursive(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }
}
string Rekursion::execute(string& x) {
    return "";
}
string Rekursion::execute(vector<double>& x) {
    cout << fibonacciRecursive(x[0]);

	return "";
}