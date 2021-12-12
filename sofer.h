#ifndef PROIECT_POO_SOFER_H
#define PROIECT_POO_SOFER_H

#include "persoana.h"
#include "comanda.h"

class sofer : public persoana {
    static int nr_comenzi;
public:
    sofer(const std::string &nume, const std::string &prenume);

    void afisare() override;

    int comanda_preluata(const comanda &c);

    ~sofer() override = default;
};


#endif //PROIECT_POO_SOFER_H
