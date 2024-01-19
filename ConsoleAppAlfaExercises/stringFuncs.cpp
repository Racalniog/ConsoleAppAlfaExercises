#include "Header.h"

string ReverseStr::execute(string& a) {
		reverse(a.begin(), a.end());
		return a;
}

string RemoveSpaces::execute(string& a) {
	a.erase(remove_if(a.begin(), a.end(), [](char c) { return std::isspace(c); }), a.end());
	return a;
}

string CountNumsInString::execute(string& a) {
	int nums = {};
	for (char c : a)
	{
		if (isdigit(c))
			nums++;
	}
	cout << nums;
	return "";
}

string Palindrome::execute(string& str) {
	std::string cleanedStr;

	// Remove non-alphanumeric characters and convert to lowercase
	for (char ch : str) {
		if (std::isalnum(ch)) {
			cleanedStr += std::tolower(ch);
		}
	}

	// Check if the cleaned string is a palindrome
	for (size_t i = 0; i < cleanedStr.length() / 2; ++i) {
		if (cleanedStr[i] != cleanedStr[cleanedStr.length() - 1 - i]) {
			return "false";
		}
	}

	return "true";
}

string RemoveLeadingSpaces::execute(string& a) {
	a.erase(a.begin(), std::find_if_not(a.begin(), a.end(), [](char c) { return std::isspace(c); }));
	return a;
}

string RemoveTrailingSpaces::execute(string& a) {
	a.erase(std::find_if_not(a.rbegin(), a.rend(), [](char c) { return std::isspace(c); }).base(), a.end());
	return a;
}

vector<pair<string, string>> extractParameters(const string& functionSignature) {
	vector<pair<string, string>> parameters;

	// Define a regular expression pattern to match parameter types and names
	regex pattern(R"((\w+)\s+(\w+))");

	// Use regex_iterator to iterate over matches in the function signature
	auto it = sregex_iterator(functionSignature.begin(), functionSignature.end(), pattern);
	auto end = sregex_iterator();

	for (; it != end; ++it) {
		// Extract matched parameter type and name
		smatch match = *it;
		if (match.size() == 3) { // Assuming two capturing groups (type and name)
			parameters.emplace_back(match[1], match[2]);
		}
	}

	return parameters;
}