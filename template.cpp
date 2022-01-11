#include "template.h"
#include "dish.h"
#include "restaurant.h"
#include <algorithm>

template<class T>
void baza_de_date<T>::adauga(const T &ob) {
    tabel.push_back(ob);
}

template<class T>
void baza_de_date<T>::sterge(const T &ob) {
    auto it = std::find(tabel.begin(), tabel.end(), ob);
    if (it != tabel.end()) {
        tabel.erase(it);
    } else {
        std::cout << "\nRegistrul " << ob.getNume() << " nu poate fi sters deoarece nu exista in baza de date."
                  << std::endl;
    }
}

template<class T>
void baza_de_date<T>::afiseaza_tabel() {
    for (const T &ob: tabel)
        std::cout << ob;
}

template
class baza_de_date<dish>;

template
class baza_de_date<restaurant>;