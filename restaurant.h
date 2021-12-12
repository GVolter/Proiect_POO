#ifndef PROIECT_POO_RESTAURANT_H
#define PROIECT_POO_RESTAURANT_H

#include "dish.h"
#include <vector>
#include <memory>

class restaurant {
    std::string nume;
    std::vector<dish> meniu;
public:
    restaurant() = default;

    explicit restaurant(const std::string &nume);

    const std::string &getNume() const;

    const std::vector<dish> getMeniu() const;

    void adauga(const dish &d);

    friend std::ostream &operator<<(std::ostream &out, const restaurant &restaurant);

    ~restaurant() = default;
};


#endif //PROIECT_POO_RESTAURANT_H
