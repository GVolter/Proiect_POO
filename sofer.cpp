#include "sofer.h"

void sofer::afisare(std::ostream &out) const {
    out << "Detalii sofer \nNume: " << nume << "\nPrenume: " << prenume << "\nVarsta: ";
    if (varsta == 0)
        out << "varsta necunoscuta";
    else
        out << varsta;
    out << "\nVehicul: ";
    if (vehicul.empty())
        out << "vehicul necunoscut";
    else
        out << vehicul;
    out << "\nNumar comenzi preluate: " << nr_comenzi << std::endl;

}

int sofer::preia_comanda(const comanda &c) {
    std::cout << nume << " " << prenume << " a preluat comanda " << c.getId() << ".\n" << std::endl;
    nr_comenzi++;
    return nr_comenzi;
}



