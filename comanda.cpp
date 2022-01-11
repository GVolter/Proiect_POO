#include "comanda.h"

int comanda::id_max = 1;

comanda::comanda(const std::shared_ptr<user> &u) : id(id_max), u(u) {
    id_max++;
}

const int &comanda::getId() const {
    return id;
}

void comanda::selecteaza_restaurant(const restaurant &res) {
    u->check_connection();
    std::cout << u->getUsername() << " a selectat Restaurantul " << res.getNume() << ".\n" << std::endl;
    res.afiseaza_meniu();
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
    bool ok = false;
    for (auto i = 0; i < nr_buc; i++) {
        auto it = std::find_if(lista.begin(), lista.end(), [&nume_dish](const dish &d) -> bool {
            return d.getNume() == nume_dish;
        });
        if (it != lista.end()) {
            lista.erase(it);
            ok = true;
        }
    }
    if (ok)
        std::cout << "A fost eliminat " << nume_dish << "x" << nr_buc << ".\n" << std::endl;
    else
        std::cout << "Dishul " << nume_dish << " nu exista in comanda." << "\n" << std::endl;
}

double comanda::pret_total() const {
    double suma = 0.0;
    for (const dish &d: getLista()) {
        suma += d.getPret();
    }
    return suma;
}

void comanda::optiune_plata() {
    u->check_connection();
    std::cout << "Suma de platit: " << pret_total() + u->taxa_de_transport(pret_total()) << "RON\n";
    std::cout
            << "Alege optiunea de plata:\n1. CARD\n2. ORDIN DE PLAT \n3. CASH (persoana fizica) / CEC (persoana juridica)"
            << std::endl;
}

void comanda::plaseaza_com(int optiune) {
    u->plata(optiune);
    std::cout << "Comanda " << id << " va fi livrata in cel mai scurt timp.\n" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const comanda &com) {
    out << "Comanda " << com.id << " include: " << std::endl;
    for (const dish &d: com.getLista()) {
        out << "\t" << d.getNume() << " " << d.getPret() << " RON" << std::endl;
    }
    out << "Pret total: " << com.pret_total() << " RON\n" << std::endl;
    return out;
}



