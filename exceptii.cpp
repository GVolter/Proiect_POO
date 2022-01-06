#include "exceptii.h"
#include <string>

using namespace std::string_literals;

eroare::eroare(const std::string &arg) : logic_error("Eroare: "s + arg) {}

eroare_pret::eroare_pret(double pret) : eroare(
        "Pretul dishului nu poate fi negativ. Pretul introdus: "s + std::to_string(pret)) {}

eroare_nume::eroare_nume() : eroare("Numele/prenumele nu poate contine cifre si caractere speciale.\n") {}

eroare_connect::eroare_connect() : eroare("Userul nu este conectat si nu poate folosi aplicatia.\n") {}

eroare_optiune::eroare_optiune() : eroare("Optiunea aleasa nu este valabila.\n") {}