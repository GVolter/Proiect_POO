#ifndef PROIECT_POO_PERSOANA_H
#define PROIECT_POO_PERSOANA_H

#include <iostream>
#include "exceptii.h"
#include <regex>

class persoana {
protected:
    std::string nume;
    std::string prenume;
public:
    persoana() = default;

    persoana(const std::string &nume, const std::string &prenume);

    virtual void afisare(std::ostream &out) const = 0;

    friend std::ostream &operator<<(std::ostream &out, const persoana &p);

    virtual ~persoana() = default;
};


#endif //PROIECT_POO_PERSOANA_H
