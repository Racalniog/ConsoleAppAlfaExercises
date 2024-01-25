#include "Header.h"

string Becher::getName() {
    return "Becher Klasse";
}

string Becher::execute(string& x) {
    return "";
}
string Becher::execute(vector<double>& x) {
    Becher kaffeeBecher("Kaffee", 250);

    kaffeeBecher.zeigeInformationen(); 

    kaffeeBecher.auffuellen();
    kaffeeBecher.zeigeInformationen(); 

    kaffeeBecher.schluckNehmen();
    kaffeeBecher.zeigeInformationen(); 

    kaffeeBecher.leertrinken();
    kaffeeBecher.zeigeInformationen(); 
    return "";
}

Becher::Becher(const std::string& inhalt, int fassungsvermoegen)
    : inhalt_(inhalt), fassungsvermoegen_(fassungsvermoegen), fuellhoehe_(0.0) {}

void Becher::auffuellen() {
    fuellhoehe_ = 1.0;
}

void Becher::leertrinken() {
    fuellhoehe_ = 0.0;
}

void Becher::schluckNehmen() {
    if (fuellhoehe_ > 0.0) {
        fuellhoehe_ -= 20.0 / fassungsvermoegen_;
        if (fuellhoehe_ < 0.0) {
            fuellhoehe_ = 0.0;
        }
    }
    else {
        std::cout << "Der Becher ist bereits leer." << std::endl;
    }
}

void Becher::zeigeInformationen() const {
    std::cout << "Inhalt: " << inhalt_ << ", Fassungsvermoegen: " << fassungsvermoegen_
        << " ml, Fuellhoehe: " << (fuellhoehe_ * 100) << "%" << std::endl;
}