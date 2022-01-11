#include "dish_factory.h"

dish dish_factory::pizza() {
    return dish{"Pizza Margherita", 23.5, false, 540, "Pizza si Paste"};
}

dish dish_factory::paste() {
    return dish{"Paste Bolognese", 26, false, 350, "Pizza si Paste"};
}

dish dish_factory::ciorba() {
    return dish{"Ciorba de legume", 12, true, 400, "Ciorbe"};
}

dish dish_factory::tocanita() {
    return dish{"Tocanita de cartofi", 16.5, true, 320, "Preparate gatite"};
}

dish dish_factory::sarmale() {
    return dish{"Sarmale cu varza", 18, false, 280, "Preparate gatite"};
}


