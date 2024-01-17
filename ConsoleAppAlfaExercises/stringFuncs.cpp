#include "Header.h"


string ReverseStr::execute(string& a) {
		reverse(a.begin(), a.end());
		return a;
}
string ReverseStr::getName() const {
		return "reverseString(string a)";
}

string reverseString(string a) {
	reverse(a.begin(), a.end());
	return a;
}

string removeSpaces(string a) {
	a.erase(remove_if(a.begin(), a.end(), isspace), a.end());
	return a;
}

int countNumsInString(string a) {
	int nums = {};
	for (char c : a)
	{
		if (isdigit(c))
			nums++;
	}
	return nums;
}

string removeLeadingSpaces(string a) {
	a.erase(a.begin(), find_if_not(a.begin(), a.end(), isspace));
	return a;
}

string removeTrailingSpaces(string a) {
	a.erase(find_if_not(a.rbegin(), a.rend(), isspace).base(), a.end());
	return a;
}