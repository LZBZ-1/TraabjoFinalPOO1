//
// Created by jalb2 on 30/09/2022.
//
#pragma once

#include "Persona.h"
#include "../Encriptacion/Password.h"
#include <vector>

#ifndef TRABAJOFINALALESIS_ADMIN_H
#define TRABAJOFINALALESIS_ADMIN_H

class Admin : public Persona{
    static int idAdmin;
private:
    int id;
    Password password;
public:
    Admin() = default;

    Admin(int dni, const string &nombre, const Password &password) : Persona(dni, nombre), password(password) {
        idAdmin++;
        Admin::id = idAdmin;
    }

    Admin(int dni, const string &nombre, int id, const Password &password) : Persona(dni, nombre), id(id),
                                                                             password(password) {
        idAdmin++;
        Admin::id = idAdmin;
    }

    static int getIdAdmin() {
        return idAdmin;
    }

    static void setIdAdmin(int idAdmin) {
        Admin::idAdmin = idAdmin;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        Admin::id = id;
    }

    const Password &getPassword() const {
        return password;
    }

    void setPassword(const Password &password) {
        Admin::password = password;
    }
};

int Admin::idAdmin = 0;

#endif //TRABAJOFINALALESIS_ADMIN_H
