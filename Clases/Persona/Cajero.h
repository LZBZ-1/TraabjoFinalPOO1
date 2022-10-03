//
// Created by jalb2 on 30/09/2022.
//
#pragma once

#include "Persona.h"
#include "../Encriptacion/Password.h"
#include <vector>

#ifndef TRABAJOFINALALESIS_CAJERO_H
#define TRABAJOFINALALESIS_CAJERO_H

class Cajero : public Persona{
    static int idCajero;
private:
    int id;
    Password password;
    bool eliminado;

public:
    Cajero() = default;

    ~Cajero() = default;

    Cajero(int dni, const string &nombre, const Password &password) : Persona(dni, nombre), password(password) {
        idCajero++;
        Cajero::id = idCajero;
    }

    Cajero(int dni, const string &nombre, int id, const Password &password, bool eliminado) : Persona(dni, nombre),
                                                                                              id(id),
                                                                                              password(password),
                                                                                              eliminado(eliminado) {
        idCajero++;
        Cajero::id = idCajero;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        Cajero::id = id;
    }

    const Password &getPassword() const {
        return password;
    }

    void setPassword(const Password &password) {
        Cajero::password = password;
    }

    bool isEliminado() const {
        return eliminado;
    }

    void setEliminado(bool eliminado) {
        Cajero::eliminado = eliminado;
    }

};

int Cajero::idCajero = 0;


#endif //TRABAJOFINALALESIS_CAJERO_H
