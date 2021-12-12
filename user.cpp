#include "user.h"
#include "exceptii.h"
#include <regex>

std::string user::token;

user::user(const std::string &nume, const std::string &prenume, const std::string &username)
        : persoana(nume, prenume), username(username) {}

const std::string &user::getUsername() const {
    return username;
}

void user::connect() {
    token = "ok";
}

void user::disconnect() {
    token.clear();
    std::cout << "Utilizatorul " << username << " s-a deconectat.\n" << std::endl;
}

void user::check_connection() {
    if (token != "ok")
        throw eroare_connect();
}

void user::afisare() {
    if (token.empty())
        std::cout << "Utilizatorul " << username << " (" << prenume << " " << nume << ") nu este conectat.\n"
                  << std::endl;
    else
        std::cout << "Utilizatorul " << username << " (" << prenume << " " << nume << ") este conectat.\n"
                  << std::endl;
}

