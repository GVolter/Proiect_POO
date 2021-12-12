//
// Created by andre on 10.12.2021.
//

#include "persoana.h"

persoana::persoana(const std::string &nume, const std::string &prenume) : nume(nume), prenume(prenume) {
    this->nume = nume;
    this->prenume = prenume;
    if (!std::regex_match(nume, std::regex("^[A-Za-z]+$")) || !std::regex_match(prenume, std::regex("^[A-Za-z]+$")))
        throw eroare_nume();
}

std::ostream &operator<<(std::ostream &out, const persoana &p) {
    out << p.nume << " " << p.prenume << std::endl;
    return out;
}
