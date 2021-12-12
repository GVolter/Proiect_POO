#ifndef PROIECT_POO_COMANDA_H
#define PROIECT_POO_COMANDA_H

#include "restaurant.h"
#include "user.h"
#include "algorithm"

class comanda {
    int nr_comanda;
    std::vector<dish> lista;
    restaurant res;
    std::shared_ptr<user> u;
public:
    comanda(int nrComanda, const restaurant &res, std::shared_ptr<user> &u);

    const int &getNrComanda() const;

    void afiseaza_meniu();

    void adauga_comanda(const dish &d, int nr_buc);

    void elimina_comanda(const std::string &nume_dish, int nr_buc);

    std::vector<dish> getLista() const;

    double pret_total() const;

    void plaseaza_com();

    friend std::ostream &operator<<(std::ostream &out, const comanda &com);

    ~comanda() = default;
};


#endif //PROIECT_POO_COMANDA_H
