#ifndef PROIECT_POO_PERSOANA_JURIDICA_H
#define PROIECT_POO_PERSOANA_JURIDICA_H


#include "user.h"

class persoana_juridica : public user {
public:
    persoana_juridica(const std::string &nume, const std::string &prenume, const std::string &username);

    void plata(int optiune) override;

    double taxa_de_transport(double pret_total) override;

    ~persoana_juridica() override = default;
};


#endif //PROIECT_POO_PERSOANA_JURIDICA_H
