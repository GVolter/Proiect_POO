#ifndef PROIECT_POO_DISH_H
#define PROIECT_POO_DISH_H

#include <iostream>
#include <memory>
#include "exceptii.h"

class dish {
protected:
    std::string nume;
    double pret;
public:
    dish(const std::string &nume, double pret);

    const std::string &getNume() const;

    const double &getPret() const;

    dish(const dish &C);

    dish &operator=(const dish &C);

    friend std::ostream &operator<<(std::ostream &out, const dish &dish);

    ~dish() = default;
};


#endif //PROIECT_POO_DISH_H
