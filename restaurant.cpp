#include "restaurant.h"

restaurant::restaurant(const std::string &nume) {
    this->nume = nume;
}

const std::string &restaurant::getNume() const {
    return nume;
}


const std::vector<dish> &restaurant::getMeniu() const {
    return meniu;
}


void restaurant::adauga(const dish &d) {
    meniu.push_back(d);
}

void restaurant::afiseaza_meniu() const {
    std::cout << "MENIU Restaurant " << nume << std::endl;
    for (const dish &d: getMeniu())
        std::cout << d;
}

std::ostream &operator<<(std::ostream &out, const restaurant &restaurant) {
    out << "RESTAURANT " << restaurant.nume;
    return out;
}