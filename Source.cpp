#include <iostream>
#include <vector>
#include "dish.h"
#include "restaurant.h"
#include "user.h"
#include "comanda.h"
#include "sofer.h"

int main() {
    dish d1{"Pizza Margherita", 21};
    dish d2{"Pizza Capriciosa", 23.5};
    dish d3{"Paste Carbonara", 29};
    dish d4{"Ciorba de perisoare", 13};

    restaurant r1{"Ceva"};
    restaurant r2{"La Maria"};

    r1.adauga(d1);
    r1.adauga(d2);
    r2.adauga(d3);
    r2.adauga(d4);

    std::vector<restaurant> restaurante;

    restaurante.push_back(r1);
    restaurante.push_back(r2);

    std::cout << "---Lista restaurante---" << std::endl;

    for (const auto &i: restaurante) {
        std::cout << i << std::endl;
    }

    std::cout << "-----------------------\n" << std::endl;

    sofer s1{"Dumitrache", "Dragos"};

    auto u1 = std::make_shared<user>("Vasile", "Ion", "test");
    u1->connect();
    u1->afisare();

    comanda com1{123, r1, u1};
    try {
        com1.afiseaza_meniu();
        com1.adauga_comanda(d2, 3);
        com1.adauga_comanda(d1, 1);
        std::cout << com1;
        com1.elimina_comanda("Pizza Capriciosa", 2);
        std::cout << com1;
        com1.plaseaza_com();
    }
    catch (eroare_connect &eroare) {
        std::cout << eroare.what() << "\n";
    }

    s1.comanda_preluata(com1);

    u1->disconnect();

    std::cout << "-------------------------///-----------------------------\n" << std::endl;

    auto u2 = std::make_shared<user>("Mircea", "Marin", "testulet");
    u2->afisare();

    try {
        comanda com2{321, r2, u2};
        com2.afiseaza_meniu();
        com2.adauga_comanda(d3, 1);
        std::cout << com2;
    }
    catch (eroare_connect &eroare) {
        std::cout << eroare.what() << "\n";
    }

    std::cout << "-------------------------///-----------------------------\n" << std::endl;

    try {
        auto u3 = std::make_shared<user>("marin", "edsfg7", "teste");
    }
    catch (eroare_nume &eroare) {
        std::cout << eroare.what() << "\n";
    }

    std::cout << "-------------------------///-----------------------------\n" << std::endl;

    u2->connect();
    u2->afisare();
    comanda com3{456, r2, u2};
    try {
        com3.afiseaza_meniu();
        com3.adauga_comanda(d3, 1);
        std::cout << com3;
        com3.plaseaza_com();
    }
    catch (eroare_connect &eroare) {
        std::cout << eroare.what() << "\n";
    }

    s1.comanda_preluata(com3);
    std::cout << "-------------------------///-----------------------------\n" << std::endl;
    s1.afisare();
    return 0;
}