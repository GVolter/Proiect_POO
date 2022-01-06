//
// Created by andre on 06.01.2022.
//

#include "sofer_builder.h"

sofer_builder &sofer_builder::nume(const std::string &nume) {
    s.nume = nume;
    return *this;
}

sofer_builder &sofer_builder::prenume(const std::string &prenume) {
    s.prenume = prenume;
    return *this;
}

sofer_builder &sofer_builder::varsta(int varsta) {
    s.varsta = varsta;
    return *this;
}

sofer_builder &sofer_builder::vehicul(const std::string &vehicul) {
    s.vehicul = vehicul;
    return *this;
}

sofer sofer_builder::build() {
    return s;
}


