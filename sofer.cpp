#include "sofer.h"

int sofer::nr_comenzi = 0;

sofer::sofer(const std::string &nume, const std::string &prenume) : persoana(nume, prenume) {}

void sofer::afisare() {
    std::cout << "Nume: " << nume << "\nPrenume: " << prenume << "\nNumar comenzi preluate: " << nr_comenzi << "\n"
              << std::endl;
}

int sofer::comanda_preluata(const comanda &c) {
    std::cout << nume << " " << prenume << " a preluat comanda " << c.getNrComanda() << ".\n" << std::endl;
    nr_comenzi++;
    return nr_comenzi;
}



