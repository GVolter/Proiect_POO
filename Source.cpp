#include <iostream>
#include <vector>

class dish {
    std::string nume;
    double pret;
public:
    dish(const std::string &nume, double pret);

    const std::string &getNume() const;

    const double &getPret() const;

    dish(const dish &C);

    dish &operator=(const dish &C);

    friend std::ostream &operator<<(std::ostream &out, const dish &dish);

    ~dish() {};
};

dish::dish(const std::string &nume, double pret) {
    this->nume = nume;
    this->pret = pret;
}

const std::string& dish::getNume() const
{
    return nume;
}

const double& dish::getPret() const
{
    return pret;
}

dish::dish(const dish &C) {
    this->nume = C.nume;
    this->pret = C.pret;
}

dish &dish::operator=(const dish &C) {
    if (this != &C) {
        this->nume = C.nume;
        this->pret = C.pret;
    }
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const dish &dish) {
    out << dish.nume << "\t" << dish.pret << std::endl;
    return out;
}


class restaurant {
    std::string nume;
    std::vector<dish> meniu;
public:
    restaurant() {};

    restaurant(const std::string &nume, const std::vector<dish> &meniu);

    const std::string &getNume() const;

    const std::vector<dish> &getMeniu() const;

    void adauga(const dish &d);

    friend std::ostream &operator<<(std::ostream &out, const restaurant &restaurant);

    ~restaurant() {};
};

restaurant::restaurant(const std::string &nume, const std::vector<dish> &meniu) {
    this->nume = nume;
    this->meniu = meniu;
}

const std::string& restaurant::getNume() const
{
    return nume;
}


const std::vector<dish> &restaurant::getMeniu() const {
    return meniu;
}


void restaurant::adauga(const dish &d) {
    meniu.push_back(d);
}

std::ostream &operator<<(std::ostream &out, const restaurant &restaurant) {
    out << "RESTAURANT " << restaurant.nume;
    return out;
}

class user {
    std::string username;
    std::string nume;
    std::string prenume;
    std::string token;

public:
    user() {};

    user(const std::string &username, const std::string &nume, const std::string &prenume);

    const std::string &getUsername() const;

    void connect();

    void disconnect();

    friend std::ostream &operator<<(std::ostream &out, const user &user);

    ~user() {};
};

user::user(const std::string &username, const std::string &nume, const std::string &prenume) {
    this->username = username;
    this->nume = nume;
    this->prenume = prenume;
}

const std::string &user::getUsername() const {
    return username;
}

void user::connect() {
    token = "ok";
}

void user::disconnect() {
    token.clear();
    std::cout << "\nUtilizatorul " << username << " s-a deconectat.\n" << std::endl;
    std::cout << "-------------------------///-----------------------------" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const user &user) {
    if (user.token.empty())
        out << "\nUtilizatorul " << user.username << " (" << user.prenume << " " << user.nume << ") nu este conectat."
            << std::endl;
    else
        out << "\nS-a conectat utilizatorul " << user.username << " (" << user.prenume << " " << user.nume << ")"
            << std::endl;
    return out;
}

class comanda {
    int nr_comanda;
    std::vector<dish> lista;
    restaurant res;
    user u;
public:
    comanda(int nr_comanda, const restaurant &restaurant, const user &user);

    void afiseaza_meniu();

    void adauga_comanda(const dish &d);

    /*void elimina_comanda(std::string nume_dish);*/
    const std::vector<dish> &getLista() const;

    double pret_total() const;

    void plaseaza_com();

    friend std::ostream &operator<<(std::ostream &out, const comanda &com);

    ~comanda() {};
};


comanda::comanda(int nr_comanda, const restaurant &res, const user &u) {
    this->nr_comanda = nr_comanda;
    this->res = res;
    this->u = u;
}

void comanda::afiseaza_meniu() {

    std::cout << "\n" << u.getUsername() << " a selectat Restaurantul " << res.getNume() << "\n\n    MENIU"
              << std::endl;
    for (const dish &d: res.getMeniu())
        std::cout << d;
    std::cout << "\n";
}

void comanda::adauga_comanda(const dish &d) {
    lista.push_back(d);
    std::cout << u.getUsername() << " a adaugat in lista " << d.getNume() << "." << std::endl;
}

const std::vector<dish> &comanda::getLista() const {
    return lista;
}

//void comanda::elimina_comanda(std::string nume_dish)
//{
//	lista.erase(std::remove_if(lista.begin(), lista.end(), [&nume_dish](const dish& d)->bool
//	{
//		return d.getNume() == nume_dish;
//	}), lista.end());
//
//
//	std::cout << "A fost eliminat " << nume_dish << "." << std::endl;
//}
//	TO DO (maybe): daca in comanda sunt x buc din acelasi dish si vreau sa elimin doar una sau <x?

double comanda::pret_total() const {
    double suma = 0.0;
    for (const dish &d: getLista()) {
        suma += d.getPret();
    }
    return suma;
}

void comanda::plaseaza_com() {
    std::cout << "Comanda " << nr_comanda << " a fost plasata." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const comanda &com) {
    out << "\nComanda " << com.nr_comanda << " include: " << std::endl;
    for (const dish &d: com.getLista()) {
        out << "\t" << d.getNume() << " " << d.getPret() << std::endl;
    }
    out << "Pret total: " << com.pret_total() << "\n" << std::endl;
    return out;
}
//TO DO (maybe): daca in comanda sunt de x buc din acelasi dish sa se afiseze o singura o data si nr_buc


int main() {
    dish d1{"Pizza", 21.5}, d2{"Paste", 24.0};

    restaurant r1{"Ceva", {d1}};
    restaurant r2{"La Maria", {d1, d2}};

    r1.adauga({d2});
    r2.adauga({"Fasole cu ciolan", 35.5});

    std::vector<restaurant> restaurante;

    restaurante.push_back(r1);
    restaurante.push_back(r2);

    std::cout << "---Lista restaurante---" << std::endl;

    for (auto i = restaurante.begin(); i != restaurante.end(); i++) {
        std::cout << (*i) << std::endl;
    }

    std::cout << "-----------------------" << std::endl;

    user u1{"test", "Vasile", "Ion"};
    u1.connect();
    std::cout << u1;

    comanda c1{123, r2, u1};

    c1.afiseaza_meniu();
    c1.adauga_comanda(d2);
    c1.adauga_comanda({"Fasole cu ciolan", 35.5});
    std::cout << c1;
    c1.adauga_comanda(d2);
    std::cout << c1;
    //c1.elimina_comanda("Fasole cu ciolan");
    //std::cout << c1;
    c1.plaseaza_com();


    u1.disconnect();

    user u2{"testulet", "Mircea", "Marin"};
    std::cout << u2;

    //comanda c2{ 321, r1, u2 };

    //c2.afiseaza_meniu();
    //c2.adauga_comanda(d1);
    //std::cout << c2;

    //u2.disconnect();

    return 0;
}