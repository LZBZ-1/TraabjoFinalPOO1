//
// Created by jalb2 on 30/09/2022.
//
#include <iostream>
#include <limits>
#include "Persona/Cliente.h"
#include "Persona/Cajero.h"
#include "Encriptacion/Base64.h"
#include "../Controlador/ClienteVector/ClienteVector.h"
#include "../Controlador/CajeroVector/CajeroVector.h"
#include "../Controlador/AdminVector/AdminVector.h"

#ifndef TRABAJOFINALALESIS_FUNCIONES_H
#define TRABAJOFINALALESIS_FUNCIONES_H

using namespace std;

void cargarDatorCliente(){
    vectorCliente.leerCsv();
    for (int i = 0; i < vectorCliente.rows(); ++i) {
        if(vectorCliente.get(i).isEliminado()){
            vectorClienteEliminado.add(vectorCliente.get(i));
            vectorCliente.deleted(vectorCliente.get(i));
            i--;
        }
    }
}

void registrarCliente(){
    string dni, nombre;

    do {
        cout<<"Ingrese el dni del cliente: ";
        cin >> dni;
    } while (dni.empty());

    if(stoi(dni) != vectorCliente.buscarPorDni(stoi(dni)).getDni()){
        cout << "Cliente no Registrado\n";
        cout << "Ingrese el nombre del cliente: ";
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        getline(cin, nombre);
        Cliente cliente = Cliente(stoi(dni),nombre);
        vectorCliente.add(cliente);
        ClienteVector::escribirCsv(cliente);
    } else {
        cout << "Cliente Registrado\n";
    }
}

void cargarDatorCajero(){
    vectorCajero.leerCsv();
    for (int i = 0; i < vectorCajero.rows(); ++i) {
        if(vectorCajero.get(i).isEliminado()){
            vectorCajeroEliminado.add(vectorCajero.get(i));
            vectorCajero.deleted(vectorCajero.get(i));
            i--;
        }
    }
}

void registarCajero(){
    string dni, nombre, pass;

    do {
        cout<<"Ingrese el dni del cajero: ";
        cin >> dni;
    } while (dni.empty());


    if(stoi(dni) != vectorCajero.buscarPorDni(stoi(dni)).getDni()){
        cout << "Cajero no Registrado\n";
        cout << "Ingrese el nombre del cajero: ";
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        getline(cin, nombre);
        cout<< "Ingrese su contrasena : ";
        getline(cin, pass);
        Password password;
        strcpy(password.password,base64::Cifrar(pass).c_str());
        Cajero cajero = Cajero(stoi(dni), nombre, password);
        vectorCajero.add(cajero);
        CajeroVector::escribirCsv(cajero);
    } else {
        cout << "Cajero Registrado\n";
    }
}

void cargarDatorAdmin(){
    vectorAdmin.leerCsv();
}

void registarAdmin(){
    string dni, nombre, pass;

    do {
        cout<<"Ingrese el dni del admin: ";
        cin >> dni;
    } while (dni.empty());


    if(stoi(dni) != vectorCajero.buscarPorDni(stoi(dni)).getDni()){
        cout << "Admin no Registrado\n";
        cout << "Ingrese el nombre del admin: ";
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        getline(cin, nombre);
        cout<< "Ingrese su contrasena : ";
        getline(cin, pass);
        Password password;
        strcpy(password.password,base64::Cifrar(pass).c_str());
        Admin admin = Admin(stoi(dni), nombre, password);
        vectorAdmin.add(admin);
        AdminVector::escribirCsv(admin);
    } else {
        cout << "Admin Registrado\n";
    }
}


#endif //TRABAJOFINALALESIS_FUNCIONES_H
