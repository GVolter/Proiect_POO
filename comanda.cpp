#include "comanda.h"

comanda::comanda(int nr_comanda, const restaurant &res, std::shared_ptr<user> &u) : nr_comanda(nr_comanda), res(res),
                                                                                    u(u) {
    if (nr_comanda < 0)
        throw eroare_nrComanda(nr_comanda);
}

void comanda::afiseaza_meniu() {
    u->check_connection();
    std::cout << u->getUsername() << " a selectat Restaurantul " << res.getNume() << ".\n\n    MENIU"
              << std::endl;
    for (const dish &d: res.getMeniu())
        std::cout << d;
    std::cout << "\n";
}

void comanda::adauga_comanda(const dish &d, int nr_buc) {
    u->check_connection();
    for (auto i = 0; i < nr_buc; i++) {
        lista.push_back(d);
    }
    std::cout << u->getUsername() << " a adaugat in lista " << nr_buc << "x" << d.getNume() << ".\n" << std::endl;
}

std::vector<dish> comanda::getLista() const {
    return lista;
}

void comanda::elimina_comanda(const std::string &nume_dish, int nr_buc) {
    u->check_connection();
    for (auto i = 0; i < nr_buc; i++) {
        auto it = std::find_if(lista.begin(), lista.end(), [&nume_dish](const dish &d) -> bool {
            return d.getNume() == nume_dish;
        });
        lista.erase(it);
    }
    std::cout << "A fost eliminat " << nume_dish << "x" << nr_buc << ".\n" << std::endl;
}

double comanda::pret_total() const {
    u->check_connection();
    double suma = 0.0;
    for (const dish &d: getLista()) {
        suma += d.getPret();
    }
    return suma;
}

void comanda::plaseaza_com() {
    u->check_connection();
    std::cout << "Comanda " << nr_comanda << " a fost plasata.\n" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const comanda &com) {
    out << "Comanda " << com.nr_comanda << " include: " << std::endl;
    for (const dish &d: com.getLista()) {
        out << "\t" << d.getNume() << " " << d.getPret() << " RON" << std::endl;
    }
    out << "Pret total: " << com.pret_total() << " RON\n" << std::endl;
    return out;
}

const int &comanda::getNrComanda() const {
    return nr_comanda;
}