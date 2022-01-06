#include "persoana_fizica.h"

persoana_fizica::persoana_fizica(const std::string &nume, const std::string &prenume, const std::string &username)
        : user(nume, prenume, username) {
    this->nume = nume;
    this->prenume = prenume;
    this->username = username;
}

void persoana_fizica::plata(int optiune) {
    std::cout << "A fost selectata optiunea " << optiune << ".\n" << std::endl;
    if (optiune == 1)
        std::cout << "Plata a fost efectuata. 0 RON de achitat la livrarea comenzii.\n" << std::endl;
    else if (optiune == 2)
        std::cout << "Suma totala va fi achitata la livrare prin curier.\n" << std::endl;
    else
        throw eroare_optiune();
}


