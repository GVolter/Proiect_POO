cmake_minimum_required(VERSION 3.21)
project(Proiect_POO)

set(CMAKE_CXX_STANDARD 14)

if (MSVC)
    add_compile_options(/W4)
else ()
    add_compile_options(-Wall -Wextra -pedantic -g)
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        add_compile_options(-stdlib=libstdc++)
    endif ()
endif ()

add_executable(Proiect_POO
        Source.cpp comanda.cpp comanda.h restaurant.cpp restaurant.h dish.cpp dish.h user.cpp user.h exceptii.cpp exceptii.h persoana.cpp persoana.h sofer.cpp sofer.h persoana_fizica.cpp persoana_fizica.h persoana_juridica.cpp persoana_juridica.h dish_factory.cpp dish_factory.h sofer_builder.cpp sofer_builder.h)
