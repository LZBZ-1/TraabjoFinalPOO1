//
// Created by jalb2 on 02/10/2022.
//
#pragma once

#include <string>
#include <cstring>
#include <fstream>
#include "../../Clases/Persona/Cajero.h"

#ifndef TRABAJOFINALALESIS_CAJEROVECTOR_H
#define TRABAJOFINALALESIS_CAJEROVECTOR_H

class CajeroVector{
private:
    vector<Cajero> cajeroVector;
public:
    CajeroVector() = default;

    ~CajeroVector() = default;

    void add(const Cajero& cajero){
        cajeroVector.push_back(cajero);
    }

    void deleted(const Cajero& cajero){
        cajeroVector.erase(cajeroVector.begin()+getPostArray(cajero));
    }

    Cajero get(int pos){
        return cajeroVector[pos];
    }

    int getPostArray(const Cajero& cajero){
        for (int i = 0; i < rows(); i++){
            if (cajero.getId() == get(i).getId()){
                return i;
            }
        }
        return -1;
    }

    Cajero buscarPorId(int id){
        for(const Cajero& cajero: cajeroVector){
            if(cajero.getId() == id){
                return cajero;
            }
        }

        return {};
    }

    Cajero buscarPorDni(int dni){
        for(const Cajero& cajero : cajeroVector){
            if(cajero.getDni() == dni){
                return cajero;
            }
        }
        return {};
    }

    Cajero buscarPorNombre(const string& nombre){
        for(const Cajero& cajero : cajeroVector){
            if(cajero.getNombre() == nombre){
                return cajero;
            }
        }

        return {};
    }

    size_t rows(){
        return cajeroVector.size();
    }

    static void escribirCsv(const Cajero& cajero){
        try {
            fstream salida;
            salida.open("cajero.csv",ios::app);
            if(salida.is_open()){
                salida << cajero.getId() << ";" << cajero.getDni() << ";" << cajero.getNombre() << ";"
                << cajero.isEliminado() << ";cajero" << cajero.getId() << ".bin;";
                salida.close();
            }
            Password password = cajero.getPassword();
            ofstream out( "cajero" + to_string(cajero.getId()) + ".bin", ios::binary | ios::out );
            out.write((char*) (&password),sizeof(password));
            out.close();

        } catch (std::exception& e){
            std::cerr << e.what() << endl;
        }
    }

    void leerCsv(){
        try {
            fstream entrada;
            int i;
            string temp[5];
            string line;
            size_t pos;
            entrada.open("cajero.csv",ios::in);
            if (entrada.is_open()) {
                while (!entrada.eof()) {
                    while(getline(entrada,line)) {
                        i = 0;
                        while((pos = line.find(';')) != string::npos) {
                            temp[i] = line.substr(0,pos);
                            line.erase(0, pos + 1);
                            i++;
                        }
                        Password password;
                        ifstream in(temp[4],ios::binary | ios::in);
                        in.read((char*) (&password), sizeof(password));
                        in.close();

                        cajeroVector.emplace_back(stoi(temp[1]),temp[2],stoi(temp[0])
                                                  ,password,temp[3] == "1");

                    }
                }
            }

        } catch (std::exception& e) {
            std::cerr << e.what() << endl;
        }
    }
};

CajeroVector vectorCajero;
CajeroVector vectorCajeroEliminado;

#endif //TRABAJOFINALALESIS_CAJEROVECTOR_H
