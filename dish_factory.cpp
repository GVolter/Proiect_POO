#include "dish_factory.h"

dish dish_factory::pizza() {
    return dish{"Pizza", 23.5};
}

dish dish_factory::paste() {
    return dish{"Paste", 26};
}

dish dish_factory::ciorba() {
    return dish{"Ciorba", 12};
}

dish dish_factory::tocanita() {
    return dish{"Tocanita", 16.5};
}

dish dish_factory::sarmale() {
    return dish{"Sarmale", 18};
}


