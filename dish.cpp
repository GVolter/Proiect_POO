#include "dish.h"

dish::dish(const std::string &nume, double pret) {
    this->nume = nume;
    this->pret = pret;
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
}

dish &dish::operator=(const dish &C) {
    if (this != &C) {
        this->nume = C.nume;
        this->pret = C.pret;
    }
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const dish &dish) {
    out << dish.nume << "\t" << dish.pret << " RON" << std::endl;
    return out;
}

