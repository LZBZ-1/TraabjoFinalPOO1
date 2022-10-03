//
// Created by jalb2 on 30/09/2022.
//

#include <iostream>
#include <limits>
#include "Clases/Persona/Cajero.h"
#include "Clases/Encriptacion/Base64.h"
#include "Controlador/CajeroVector/CajeroVector.h"

using namespace std;

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
        cout << "Cliente Registrado\n";
    }
}

int main(){
    cargarDatorCajero();
    registarCajero();

    cout << vectorCajero.get(0).getPassword().password << endl;
    return 0;
}