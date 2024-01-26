#pragma once

// TODO: Fit input better to all exceptional functions!
#include <iostream>
#include <fstream>
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
#include <ctime>
#include <thread>

#include "Becher.h"

extern std::ofstream logFile;

std::vector<std::pair<std::string, std::string>> ExtractParameters(const std::string& functionSignature);

class BaseFunction {
public:
    virtual std::string Execute(std::string& str) = 0;
    virtual std::string Execute(std::vector<double>&) = 0;
    virtual std::string GetName() = 0;
};

class Becher : public BaseFunction {
public:
    Becher() = default;
    Becher(const std::string& inhalt, int fassungsvermoegen);
    std::string Execute(std::string& a);
    std::string Execute(std::vector<double>& userVector);
    std::string GetName();
    void Auffuellen();
    void Leertrinken();
    void SchluckNehmen();
    void ZeigeInformationen() const;

private:
    std::string inhalt_;
    int fassungsvermoegen_;
    double fuellhoehe_;
};

class Vector : public BaseFunction {
public:
    std::string Execute(std::string& a);
    std::string Execute(std::vector<double>& userVector);
    std::string GetName() {
        return "vecInit()";
    }
};

class VectorMinMax : public BaseFunction {
public:
    std::string Execute(std::string& a);
    std::string Execute(std::vector<double>& userVector);
    std::string GetName() {
        return "minMax( vector<double>& vec)";
    }
};

class VectorReverse : public BaseFunction {
public:
    std::string Execute(std::string& a);
    std::string Execute(std::vector<double>& userVector);
    std::string GetName() {
        return "reversed( vector<double>& v)";
    }
};

class VectorRound : public BaseFunction {
public:
    std::string Execute(std::string& a);
    std::string Execute(std::vector<double>& userVector);
    std::string GetName() {
        return "roundVector(vector<double>& v) ";
    }
};

class ReverseStr : public BaseFunction {
public:
    std::string Execute(std::string& a);
    std::string Execute(std::vector<double>& userVector);
    std::string GetName() {
        return "reverseString(string a)";
    }
};

class RemoveSpaces : public BaseFunction {
public:
    std::string Execute(std::string& a);
    std::string Execute(std::vector<double>& userVector);
    std::string GetName() {
        return "removeSpaces(string a)";
    }
};

class RemoveLeadingSpaces : public BaseFunction {
public:
    std::string Execute(std::string& a);
    std::string Execute(std::vector<double>& userVector);
    std::string GetName() {
        return "removeLeadingSpaces(string a)";
    }
};

class RemoveTrailingSpaces : public BaseFunction {
public:
    std::string Execute(std::string& a);
    std::string Execute(std::vector<double>& userVector);
    std::string GetName() {
        return "removeTrailingSpaces(string a)";
    }
};

class CountNumsInString : public BaseFunction {
public:
    std::string Execute(std::string& a);
    std::string Execute(std::vector<double>& userVector);
    std::string GetName() {
        return "countNumsInString(string a)";
    }
};

class Palindrome : public BaseFunction {
public:
    std::string Execute(std::string& a);
    std::string Execute(std::vector<double>& userVector);
    std::string GetName() {
        return "isPalindrome(string a)";
    }
};

class Lotto : public BaseFunction {
public:
    std::string Execute(std::string& a);
    std::string Execute(std::vector<double>& userVector);
    void GenerateLottoNumbers(const std::vector<double>& targetNumbers);
    std::string GetName();
};

class Rekursion : public BaseFunction {
public:
    std::string Execute(std::string& a);
    std::string Execute(std::vector<double>& userVector);
    std::string GetName();
};

std::unique_ptr<int[]> CreateArray(int a);
void PrintArray(std::unique_ptr<int[]> a);
std::unique_ptr<int[]> FillArray(std::unique_ptr<int[]> a);

template <typename... Args>
void LogOutput(Args&&... args);

void LogInput(std::string& input);

class TicTacToe : public BaseFunction {
public:
    std::string Execute(std::vector<double>& userVector);
    std::string Execute(std::string& a);
    std::string GetName();
};
