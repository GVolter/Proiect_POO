#include "persoana_fizica.h"

persoana_fizica::persoana_fizica(const std::string &nume, const std::string &prenume, const std::string &username)
        : user(nume, prenume, username) {}

void persoana_fizica::plata(int optiune) {
    std::cout << "A fost selectata optiunea " << optiune << ".\n" << std::endl;
    switch (optiune) {
        case 1:
            std::cout << "Plata a fost efectuata. 0 RON de achitat la livrarea comenzii.\n" << std::endl;
            break;
        case 2:
            std::cout << "Optiune selectata: ORDIN DE PLATA.\nOrdin de plata acceptat.\n" << std::endl;
            break;
        case 3:
            std::cout << "Suma totala va fi achitata la livrare prin curier.\n" << std::endl;
            break;
        default:
            throw eroare_optiune();
    }
}

double persoana_fizica::taxa_de_transport(double pret_total) {
    double taxa;
    if (pret_total < 50)
        taxa = 3 * pret_total / 10;
    else if (pret_total >= 50 && pret_total < 100)
        taxa = 2 * pret_total / 10;
    else
        taxa = 0;
    return taxa;
}


