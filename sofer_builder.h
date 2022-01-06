#ifndef PROIECT_POO_SOFER_BUILDER_H
#define PROIECT_POO_SOFER_BUILDER_H


#include "sofer.h"

class sofer_builder {
    sofer s;
public:
    sofer_builder() = default;

    sofer_builder &nume(const std::string &nume);

    sofer_builder &prenume(const std::string &prenume);

    sofer_builder &varsta(int varsta);

    sofer_builder &vehicul(const std::string &vehicul);

    sofer build();
};


#endif //PROIECT_POO_SOFER_BUILDER_H
