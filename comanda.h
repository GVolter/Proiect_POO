#ifndef PROIECT_POO_COMANDA_H
#define PROIECT_POO_COMANDA_H

#include "restaurant.h"
#include "user.h"
#include <algorithm>

class comanda {
protected:
    int id;
    static int id_max;
    std::vector<dish> lista;
    std::shared_ptr<user> u;
public:
    comanda() = default;

    comanda(const std::shared_ptr<user> &u);

    const int &getId() const;

    void selecteaza_restaurant(const restaurant &res);

    void adauga_comanda(const dish &d, int nr_buc);

    void elimina_comanda(const std::string &nume_dish, int nr_buc);

    std::vector<dish> getLista() const;

    double pret_total() const;

    void optiune_plata();

    void plaseaza_com(int optiune);

    friend std::ostream &operator<<(std::ostream &out, const comanda &com);

    ~comanda() = default;
};


#endif //PROIECT_POO_COMANDA_H
