//
// Created by jalb2 on 02/10/2022.
//
#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "../../Clases/Persona/Cliente.h"
#include "../../Clases/Conversores.h"

#ifndef TRABAJOFINALALESIS_CLIENTEVECTOR_H
#define TRABAJOFINALALESIS_CLIENTEVECTOR_H

class ClienteVector{
private:
    vector<Cliente> clienteVector;
public:
    ClienteVector() = default;

    void add(const Cliente& cliente){
        clienteVector.push_back(cliente);
    }

    void deleted(const Cliente& cliente){
        clienteVector.erase(clienteVector.begin() + getPostArray(cliente));
    }

    Cliente get(int pos){
        return clienteVector[pos];
    }

    int getPostArray(const Cliente& cliente){
        for (int i = 0; i < rows(); i++){
            if (cliente.getId() == get(i).getId()){
                return i;
            }
        }
        return -1;
    }

    Cliente buscarPorDni(int dni){
        for(const Cliente& cliente : clienteVector){
            if(cliente.getDni() == dni){
                return cliente;
            }
        }

        return {};
    }

    Cliente buscarPorNombre(const string& nombre){
        for(const Cliente& cliente : clienteVector){
            if (nombre == cliente.getNombre()){
                return cliente;
            }
        }

        return {};
    }

    size_t rows(){
        return clienteVector.size();
    }

    static void escribirCsv(const Cliente& cliente){
        try {
            fstream salida;
            salida.open("cliente.csv",ios::app);
            if(salida.is_open()){
                salida << cliente.getId() << ";" << cliente.getDni() << ";" << cliente.getNombre() << ";"
                       << cliente.isEliminado() << ";" << endl;
                salida.close();
            }
        } catch (std::exception& e){
            std::cerr << e.what() << endl;
        }
    }

    void leerCsv(){
        try {
            fstream entrada;
            int i;
            string temp[4];
            string line;
            size_t pos;
            entrada.open("cliente.csv",ios::in);
            if (entrada.is_open()) {
                while (!entrada.eof()) {
                    while(getline(entrada,line)) {
                        i = 0;
                        while((pos = line.find(';')) != string::npos) {
                            temp[i] = line.substr(0,pos);
                            line.erase(0, pos + 1);
                            i++;
                        }

                        clienteVector.emplace_back(stoi(temp[1]),temp[2],stoi(temp[0])
                                                        ,temp[3] == "1");
                    }
                }
            }

        } catch (std::exception& e) {
            std::cerr << e.what() << endl;
        }
    }
};

ClienteVector vectorCliente;
ClienteVector vectorClienteEliminado;

#endif //TRABAJOFINALALESIS_CLIENTEVECTOR_H
