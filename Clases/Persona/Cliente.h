//
// Created by jalb2 on 29/09/2022.
//

#pragma once

#include "Persona.h"

#ifndef TRABAJOFINALALESIS_CLIENTE_H
#define TRABAJOFINALALESIS_CLIENTE_H

class Cliente : public Persona{
    static int idCliente;
private:
    int id;
    bool eliminado = false;
public:
    Cliente() = default;

    Cliente(int dni, const string &nombre) : Persona(dni, nombre) {
        idCliente++;
        Cliente::id = idCliente;
    }

    Cliente(int dni, const string &nombre, int id, bool eliminado) : Persona(dni, nombre), id(id),
                                                                     eliminado(eliminado) {
        idCliente++;
        Cliente::id = idCliente;
    }

    ~Cliente() override = default;

    int getId() const {
        return id;
    }

    void setId(int id) {
        Cliente::id = id;
    }

    bool isEliminado() const {
        return eliminado;
    }

    void setEliminado(bool eliminado) {
        Cliente::eliminado = eliminado;
    }
};



int Cliente::idCliente = 0;


#endif //TRABAJOFINALALESIS_CLIENTE_H
