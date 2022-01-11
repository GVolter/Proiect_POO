#ifndef PROIECT_POO_USER_H
#define PROIECT_POO_USER_H

#include "persoana.h"

class user : public persoana {
protected:
    std::string username;
    std::string token;

public:
    user() = default;

    user(const std::string &nume, const std::string &prenume, const std::string &username);

    const std::string &getUsername() const;

    void connect();

    void disconnect();

    void afisare(std::ostream &out) const override;

    void check_connection() const;

    virtual void plata(int optiune) = 0;

    virtual double taxa_de_transport(double pret_total) = 0;

    ~user() override = default;
};


#endif //PROIECT_POO_USER_H
