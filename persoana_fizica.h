#ifndef PROIECT_POO_PERSOANA_FIZICA_H
#define PROIECT_POO_PERSOANA_FIZICA_H


#include "user.h"

class persoana_fizica : public user {
public:
    persoana_fizica(const std::string &nume, const std::string &prenume, const std::string &username);

    void plata(int optiune) override;

    ~persoana_fizica() override = default;
};


#endif //PROIECT_POO_PERSOANA_FIZICA_H
