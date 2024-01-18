#pragma once

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

using namespace std;
using namespace chrono;

vector<pair<string, string>> extractParameters(const string& functionSignature);

class BaseFunction {
public:
	virtual string execute(string& str) = 0;
	virtual string getName() const = 0;
	virtual ~BaseFunction() = default;
};

class ReverseStr : public BaseFunction {
public:
	string execute(string& a);
	string getName() const;
};

class RemoveSpaces: public BaseFunction {
public:
	string execute(string& a);
	string getName() const;
};

class Lotto: public BaseFunction {
public:
	string execute(string& a);
	string getName() const;
};

unique_ptr<int[]> createArray(int a);
void printArray(unique_ptr<int[]> a);
unique_ptr<int[]> fillArray(unique_ptr<int[]> a);

string reverseString(string a);
string removeSpaces(string a);
int countNumsInString(string a);
string removeLeadingSpaces(string a);
string removeTrailingSpaces(string a);


class TicTacToe : public BaseFunction {
public:
	string execute(string& a);
	string getName() const;
};