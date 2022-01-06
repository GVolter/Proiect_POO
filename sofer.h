#ifndef PROIECT_POO_SOFER_H
#define PROIECT_POO_SOFER_H

#include "persoana.h"
#include "comanda.h"

class sofer : public persoana {
    int nr_comenzi = 0;
    int varsta = 0;
    std::string vehicul;
public:
    sofer() = default;

    void afisare(std::ostream &out) const override;

    int preia_comanda(const comanda &c);

    friend class sofer_builder;

    ~sofer() override = default;
};


#endif //PROIECT_POO_SOFER_H
