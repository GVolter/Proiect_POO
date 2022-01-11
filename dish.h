#ifndef PROIECT_POO_DISH_H
#define PROIECT_POO_DISH_H

#include <iostream>
#include <memory>
#include "exceptii.h"

class dish {
    std::string nume;
    double pret;
    bool vegetarian;
    double cantitate;
    std::string categorie;
public:
    dish(const std::string &nume, double pret, bool vegetarian, double cantitate, const std::string &categorie);

    const std::string &getNume() const;

    const double &getPret() const;

    dish(const dish &C);

    dish &operator=(const dish &C);

    friend bool operator==(const dish &lhs, const dish &rhs);

    friend std::ostream &operator<<(std::ostream &out, const dish &dish);

    ~dish() = default;
};


#endif //PROIECT_POO_DISH_H
