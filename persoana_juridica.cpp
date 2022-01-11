#include "persoana_juridica.h"

persoana_juridica::persoana_juridica(const std::string &nume, const std::string &prenume, const std::string &username)
        : user(nume, prenume, username) {}

void persoana_juridica::plata(int optiune) {
    std::cout << "A fost selectata optiunea " << optiune << ".\n" << std::endl;
    switch (optiune) {
        case 1:
            std::cout << "Optiune selectata: CARD. \nTranzactia a fost acceptata.\n" << std::endl;
            break;
        case 2:
            std::cout << "Optiune selectata: ORDIN DE PLATA.\nOrdin de plata acceptat.\n" << std::endl;
            break;
        case 3:
            std::cout << "Optiune selectata: CEC. \nCecul va fi inmanat soferului la livrarea comenzii.\n" << std::endl;
            break;
        default:
            throw eroare_optiune();
    }
}

double persoana_juridica::taxa_de_transport(double pret_total) {
    double taxa;
    if (pret_total < 50)
        taxa = pret_total / 3;
    else if (pret_total >= 50 && pret_total < 100)
        taxa = pret_total / 4;
    else
        taxa = 0;
    return taxa;
}

