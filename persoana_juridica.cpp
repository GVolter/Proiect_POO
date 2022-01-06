#include "persoana_juridica.h"

persoana_juridica::persoana_juridica(const std::string &nume, const std::string &prenume, const std::string &username)
        : user(nume, prenume, username) {
    this->nume = nume;
    this->prenume = prenume;
    this->username = username;
}

void persoana_juridica::plata(int optiune) {
    std::cout << "A fost selectata optiunea " << optiune << ".\n" << std::endl;
    if (optiune == 1)
        std::cout << "Tranzactia a fost acceptata.\n" << std::endl;
    else
        throw eroare_optiune();
}