#ifndef PROIECT_POO_USER_H
#define PROIECT_POO_USER_H

#include "persoana.h"

class user : public persoana {
    std::string username;
    static std::string token;

public:
    user() = default;

    user(const std::string &nume, const std::string &prenume, const std::string &username);

    const std::string &getUsername() const;

    static void connect();

    void disconnect();

    void afisare() override;

    static void check_connection();

    ~user() override = default;
};


#endif //PROIECT_POO_USER_H
