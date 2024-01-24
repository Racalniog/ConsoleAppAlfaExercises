#pragma once
//Header file for class, function definitions and includes
//TODO rewrite input and output for functions with input handler!
#include <iostream>
#include <string>
#include <chrono>
#include <array>
#include <algorithm>
#include <functional>
#include <map>
#include <vector>
#include <sstream>
#include <set>
#include <iomanip>
#include <regex>
#include <fstream>
#include <ctime>
#include <thread>

using namespace std;
using namespace chrono;

extern ofstream logFile;
vector<pair<string, string>> extractParameters(const string& functionSignature);

class BaseFunction {
public:
	virtual string execute(string& str) = 0;
	virtual string execute(vector<double>&) = 0;
	virtual string getName() const = 0;
};

class Vector : public BaseFunction {
public:
	string execute(string& a);
	string execute(vector<double>& userVector);
	string getName() const {
		return "vecInit()";
	}
};

class VectorMinMax : public BaseFunction {
public:
	string execute(string& a);
	string execute(vector<double>& userVector);
	string getName() const {
		return "minMax(const vector<double>& vec)";
	}
};

class VectorReverse : public BaseFunction {
public:
	string execute(string& a);
	string execute(vector<double>& userVector);
	string getName() const {
		return "reversed(const vector<double>& v)";
	}
};

class VectorRound : public BaseFunction {
public:
	string execute(string& a);
	string execute(vector<double>& userVector);
	string getName() const {
		return "roundVector(vector<double>& v) ";
	}
};

class ReverseStr : public BaseFunction {
public:
	string execute(string& a);
	string execute(vector<double>& userVector);
	string getName() const {
		return "reverseString(string a)";
	}
};

class RemoveSpaces: public BaseFunction {
public:
	string execute(string& a);
	string execute(vector<double>& userVector);
	string getName() const {
		return "removeSpaces(string a)";
	}
};

class RemoveLeadingSpaces : public BaseFunction {
public:
	string execute(string& a);
	string execute(vector<double>& userVector);
	string getName() const {
		return "removeLeadingSpaces(string a)";
	}
};

class RemoveTrailingSpaces : public BaseFunction {
public:
	string execute(string& a);
	string execute(vector<double>& userVector);
	string getName() const {
		return "removeTrailingSpaces(string a)";
	}
};

class CountNumsInString : public BaseFunction {
public:
	string execute(string& a);
	string execute(vector<double>& userVector);
	string getName() const {
		return "countNumsInString(string a)";
	}
};

class Palindrome : public BaseFunction {
public:
	string execute(string& a);
	string execute(vector<double>& userVector);
	string getName() const {
		return "isPalindrome(string a)";
	}
};

class Lotto: public BaseFunction {
public:
	string execute(string& a);
	string execute(vector<double>& userVector);
	void generateLottoNumbers(const std::vector<double>& targetNumbers);
	string getName() const;
};

unique_ptr<int[]> createArray(int a);
void printArray(unique_ptr<int[]> a);
unique_ptr<int[]> fillArray(unique_ptr<int[]> a);

template <typename... Args>
void logOutput(Args&&... args);
void logInput(std::string& input);
class TicTacToe : public BaseFunction {
public:
	string execute(vector<double>& userVector);
	string execute(string& a);
	string getName() const;
};
