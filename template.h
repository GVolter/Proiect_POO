#ifndef PROIECT_POO_TEMPLATE_H
#define PROIECT_POO_TEMPLATE_H

#include <vector>
#include <iostream>

template<class T>
class baza_de_date {
    std::vector<T> tabel;
public:
    void adauga(const T &ob);

    void sterge(const T &ob);

    void afiseaza_tabel();
};

#endif //PROIECT_POO_TEMPLATE_H
