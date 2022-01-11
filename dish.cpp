#include "dish.h"

dish::dish(const std::string &nume, double pret, bool vegetarian, double cantitate, const std::string &categorie)
        : nume(nume), pret(pret), vegetarian(vegetarian), cantitate(cantitate), categorie(categorie) {
    if (pret < 0)
        throw eroare_pret(pret);
}

const std::string &dish::getNume() const {
    return nume;
}

const double &dish::getPret() const {
    return pret;
}

dish::dish(const dish &C) {
    this->nume = C.nume;
    this->pret = C.pret;
    this->vegetarian = C.vegetarian;
    this->cantitate = C.cantitate;
    this->categorie = C.categorie;
}

dish &dish::operator=(const dish &C) {
    if (this != &C) {
        this->nume = C.nume;
        this->pret = C.pret;
        this->vegetarian = C.vegetarian;
        this->cantitate = C.cantitate;
        this->categorie = C.categorie;
    }
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const dish &dish) {
    out << dish.nume << "\t" << dish.categorie << "\t";
    if (dish.vegetarian)
        out << "vegetarian" << "\t";
    else
        out << "non-vegetarian" << "\t";
    out << dish.cantitate << "g\t" << dish.pret << " RON" << std::endl;
    return out;
}

bool operator==(const dish &lhs, const dish &rhs) {
    if (lhs.nume == rhs.nume && lhs.pret == rhs.pret && lhs.vegetarian == rhs.vegetarian
        && lhs.cantitate == rhs.cantitate && lhs.categorie == rhs.categorie)
        return true;
    else
        return false;
}



