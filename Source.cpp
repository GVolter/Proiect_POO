#include <iostream>
#include <vector>
#include "dish.h"
#include "restaurant.h"
#include "comanda.h"
#include "sofer.h"
#include "dish_factory.h"
#include "persoana_fizica.h"
#include "persoana_juridica.h"
#include "sofer_builder.h"

int main() {
    dish d1 = dish_factory::pizza();
    dish d2 = dish_factory::paste();
    dish d3 = dish_factory::ciorba();
    dish d4 = dish_factory::tocanita();
    dish d5 = dish_factory::sarmale();


    restaurant r1{"La Ion"};
    restaurant r2{"La Maria"};

    r1.adauga(d1);
    r1.adauga(d2);
    r1.adauga(d5);
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

    sofer_builder s;
    sofer s1 = s.nume("Dumitrache").prenume("Dragos").vehicul("bicicleta").build();

    auto pj1 = std::make_shared<persoana_juridica>("Vasile", "Ion", "test");
    pj1->connect();
    std::cout << *pj1;

    comanda com1{r1, pj1};
    com1.selecteaza_restaurant();
    com1.adauga_comanda(d2, 3);
    com1.adauga_comanda(d1, 1);
    std::cout << com1;
    com1.elimina_comanda("Paste", 2);
    std::cout << com1;
    try {
        com1.plaseaza_com(2);
    }
    catch (eroare_optiune &eroare) {
        std::cout << eroare.what() << "\n";
    }
    com1.plaseaza_com(1);
    s1.preia_comanda(com1);
    pj1->disconnect();

    std::cout << "-------------------------///-----------------------------\n" << std::endl;

    auto pf1 = std::make_shared<persoana_fizica>("Mircea", "Marin", "testulet");
    std::cout << *pf1;

    try {
        comanda com2{r2, pf1};
        com2.selecteaza_restaurant();
        com2.adauga_comanda(d3, 1);
        std::cout << com2;
    }
    catch (eroare_connect &eroare) {
        std::cout << eroare.what() << "\n";
    }

    std::cout << "-------------------------///-----------------------------\n" << std::endl;

    try {
        auto pj2 = std::make_shared<persoana_juridica>("marin", "edsfg7", "teste");
    }
    catch (eroare_nume &eroare) {
        std::cout << eroare.what() << "\n";
    }

    std::cout << "-------------------------///-----------------------------\n" << std::endl;

    pf1->connect();
    std::cout << *pf1;
    comanda com3{r2, pf1};
    try {
        com3.selecteaza_restaurant();
        com3.adauga_comanda(d3, 1);
        std::cout << com3;
        com3.plaseaza_com(2);
    }
    catch (eroare_connect &eroare) {
        std::cout << eroare.what() << "\n";
    }

    s1.preia_comanda(com3);
    std::cout << "-------------------------///-----------------------------\n" << std::endl;
    std::cout << s1;
    return 0;
}