#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <array>
#include <algorithm>

using namespace std;

string stringConcat(string a, string b);
unique_ptr<int[]> createArray(int a);
void printArray(unique_ptr<int[]> a);
unique_ptr<int[]> fillArray(unique_ptr<int[]> a);

string reverseString(string a);
string removeSpaces(string a);
int countNumsInString(string a);
string removeLeadingSpaces(string a);
string removeTrailingSpaces(string a);
