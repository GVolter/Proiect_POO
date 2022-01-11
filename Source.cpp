#include <iostream>
#include "dish.h"
#include "restaurant.h"
#include "comanda.h"
#include "sofer.h"
#include "dish_factory.h"
#include "persoana_fizica.h"
#include "persoana_juridica.h"
#include "sofer_builder.h"
#include "template.h"

int main() {
    dish d1 = dish_factory::pizza();
    dish d2 = dish_factory::paste();
    dish d3 = dish_factory::ciorba();
    dish d4 = dish_factory::tocanita();
    dish d5 = dish_factory::sarmale();


    restaurant r1{"La Ion"};
    restaurant r2{"La Maria"};
    restaurant r3{"Mamma mia"};

    baza_de_date<dish> bd_dish;
    bd_dish.adauga(d1);
    bd_dish.adauga(d2);
    bd_dish.adauga(d3);
    bd_dish.adauga(d4);
    bd_dish.adauga(d5);
    bd_dish.afiseaza_tabel();

    r1.adauga(d1);
    r1.adauga(d2);
    r1.adauga(d5);
    r2.adauga(d3);
    r2.adauga(d4);

    baza_de_date<restaurant> bd_r;
    bd_r.adauga(r1);
    bd_r.adauga(r2);
    bd_r.sterge(r3);

    std::cout << "\n---Lista restaurante---" << std::endl;

    bd_r.afiseaza_tabel();

    std::cout << "-----------------------\n" << std::endl;

    sofer_builder s;
    sofer s1 = s.nume("Dumitrache").prenume("Dragos").vehicul("bicicleta").build();

    auto pj1 = std::make_shared<persoana_juridica>("Vasile", "Ion", "test");
    pj1->connect();
    std::cout << *pj1;

    comanda com1{pj1};

    try {
        com1.selecteaza_restaurant(r1);
        com1.adauga_comanda(d2, 3);
        com1.adauga_comanda(d1, 1);
        std::cout << com1;
        com1.elimina_comanda("Paste", 2);
        com1.elimina_comanda("Paste Bolognese", 2);
        std::cout << com1;
        try {
            com1.plaseaza_com(4);
        }
        catch (eroare_optiune &eroare) {
            std::cout << eroare.what() << "\n";
        }
        com1.optiune_plata();
        com1.plaseaza_com(1);
    }
    catch (eroare_connect &eroare) {
        std::cout << eroare.what() << "\n";
    }
    s1.preia_comanda(com1);
    pj1->disconnect();

    std::cout << "-------------------------///-----------------------------\n" << std::endl;

    auto pf1 = std::make_shared<persoana_fizica>("Mircea", "Marin", "testulet");
    std::cout << *pf1;

    try {
        comanda com2{pf1};
        com2.selecteaza_restaurant(r2);
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
    comanda com3{pf1};
    try {
        com3.selecteaza_restaurant(r2);
        com3.adauga_comanda(d3, 1);
        std::cout << com3;
        com3.optiune_plata();
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