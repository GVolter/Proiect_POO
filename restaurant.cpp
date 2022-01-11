#include "restaurant.h"

restaurant::restaurant(const std::string &nume) {
    this->nume = nume;
}

const std::string &restaurant::getNume() const {
    return nume;
}

void restaurant::adauga(const dish &d) {
    meniu.push_back(d);
}

void restaurant::afiseaza_meniu() const {
    std::cout << "MENIU Restaurant " << nume << std::endl;
    for (const dish &d: meniu)
        std::cout << d;
}

std::ostream &operator<<(std::ostream &out, const restaurant &restaurant) {
    out << "RESTAURANT " << restaurant.nume << std::endl;
    return out;
}

bool operator==(const restaurant &lhs, const restaurant &rhs) {
    if (lhs.nume == rhs.nume && lhs.meniu == rhs.meniu)
        return true;
    else
        return false;
}
