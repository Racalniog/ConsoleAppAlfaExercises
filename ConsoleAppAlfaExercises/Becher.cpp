#include "Header.h"

BecherAufdruck::BecherAufdruck(const std::string& inhalt, int fassungsvermoegen, std::string aufdruck) :
    Becher(inhalt,fassungsvermoegen), aufdruck_(aufdruck){}

std::string BecherAufdruck::getAufdruck() const{
    return aufdruck_;
}

std::string BecherAufdruck::Execute(std::vector<double>& x) {
    std::vector<Becher> Bechers;
    std::vector<BecherAufdruck> BechersAufdruck;

    Becher kaffeeBecher("Kaffee", 250);
    BecherAufdruck wowBecher("Wowsauce", 100, "WOW");
    wowBecher.Auffuellen();
    for (size_t i = 0; i < 5; i++)
    {
        Bechers.push_back(kaffeeBecher);
        BechersAufdruck.push_back(wowBecher);
    }
    
    for (size_t i = 0; i < 5; i++)
    {
        Bechers[i].Leertrinken();
        Bechers[i].ZeigeInformationen();
        BechersAufdruck[i].Leertrinken();
        BechersAufdruck[i].ZeigeInformationen();
        BechersAufdruck[i].getAufdruck();
    }
    return "";
}
std::string BecherAufdruck::GetName() {
    return "BecherAufdruck Klasse";
}
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
