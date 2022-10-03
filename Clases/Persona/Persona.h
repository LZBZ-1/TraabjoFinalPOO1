//
// Created by jalb2 on 26/09/2022.
//

#pragma once

#include <iostream>
#include <utility>

using namespace std;

#ifndef TRABAJOFINALALESIS_PERSONA_H
#define TRABAJOFINALALESIS_PERSONA_H

class Persona{
protected:
    int dni;
    string nombre;
public:
    Persona() = default;

    Persona(int dni, const string &nombre) : dni(dni), nombre(nombre) {}

    virtual ~Persona() = default;

    int getDni() const {
        return dni;
    }

    void setDni(int dni) {
        Persona::dni = dni;
    }

    const string &getNombre() const {
        return nombre;
    }

    void setNombre(const string &nombre) {
        Persona::nombre = nombre;
    }
};

#endif //TRABAJOFINALALESIS_PERSONA_H
