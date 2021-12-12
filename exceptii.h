#ifndef PROIECT_POO_EXCEPTII_H
#define PROIECT_POO_EXCEPTII_H

#include <stdexcept>

class eroare : public std::logic_error {
public:
    explicit eroare(const std::string &arg);
};

class eroare_pret : public eroare {
public:
    explicit eroare_pret(double pret);
};

class eroare_nrComanda : public eroare {
public:
    explicit eroare_nrComanda(int nrComanda);
};

class eroare_nume : public eroare {
public:
    eroare_nume();
};

class eroare_connect : public eroare {
public:
    eroare_connect();
};

#endif //PROIECT_POO_EXCEPTII_H
