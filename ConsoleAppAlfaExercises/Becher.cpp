#include "Header.h"

std::string Becher::GetName() {
    return "Becher Klasse";
}

std::string Becher::Execute(std::string& x) {
    return "";
}

std::string Becher::Execute(std::vector<double>& x) {
    Becher kaffeeBecher("Kaffee", 250);

    kaffeeBecher.ZeigeInformationen();

    kaffeeBecher.Auffuellen();
    kaffeeBecher.ZeigeInformationen();

    kaffeeBecher.SchluckNehmen();
    kaffeeBecher.ZeigeInformationen();

    kaffeeBecher.Leertrinken();
    kaffeeBecher.ZeigeInformationen();

    return "";
}

Becher::Becher(const std::string& inhalt, int fassungsvermoegen)
    : inhalt_(inhalt), fassungsvermoegen_(fassungsvermoegen), fuellhoehe_(0.0) {}

void Becher::Auffuellen() {
    fuellhoehe_ = 1.0;
}

void Becher::Leertrinken() {
    fuellhoehe_ = 0.0;
}

void Becher::SchluckNehmen() {
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

void Becher::ZeigeInformationen() const {
    std::cout << "Inhalt: " << inhalt_ << ", Fassungsvermoegen: " << fassungsvermoegen_
        << " ml, Fuellhoehe: " << (fuellhoehe_ * 100) << "%" << std::endl;
}
