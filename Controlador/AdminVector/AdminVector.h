//
// Created by jalb2 on 03/10/2022.
//
#pragma once

#include <fstream>
#include <vector>
#include "../../Clases/Persona/Admin.h"


#ifndef TRABAJOFINALALESIS_ADMINVECTOR_H
#define TRABAJOFINALALESIS_ADMINVECTOR_H

class AdminVector {
private:
    vector<Admin> adminVector;
public:
    AdminVector() = default;
    ~AdminVector() = default;

    void add(const Admin& admin){
        adminVector.push_back(admin);
    }

    void deleted(const Admin& admin){
        adminVector.erase(adminVector.begin() + getPostArray(admin));
    }

    Admin get(int pos){
        return adminVector[pos];
    }

    int getPostArray(const Admin& admin){
        for (int i = 0; i < rows(); i++){
            if (admin.getId() == get(i).getId()){
                return i;
            }
        }
        return -1;
    }

    size_t rows(){
        return adminVector.size();
    }

    Admin buscarPorId(int id){
        for(const Admin& admin : adminVector){
            if(admin.getId() == id){
                return admin;
            }
        }
        return {};
    }

    Admin buscarPorDni(int dni){
        for(const Admin& admin : adminVector){
            if(admin.getDni() == dni){
                return admin;
            }
        }
        return {};
    }

    Admin buscarPorNombre(string nom){
        for(const Admin& admin : adminVector){
            if(admin.getNombre() == nom){
                return admin;
            }
        }
        return {};
    }

    bool isVacio(){
        return adminVector.empty();
    }

    static void escribirCsv(const Admin& admin){
        try {
            fstream salida;
            salida.open("admin.csv",ios::app);
            if(salida.is_open()){
                salida << admin.getId() << ";" << admin.getDni() << ";" << admin.getNombre()
                << ";admin" << admin.getId() << ".bin;";
                salida.close();
            }
            Password password = admin.getPassword();
            ofstream out( "admin" + to_string(admin.getId()) + ".bin", ios::binary | ios::out );
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
            string temp[4];
            string line;
            size_t pos;
            entrada.open("admin.csv",ios::in);
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
                        ifstream in(temp[3],ios::binary | ios::in);
                        in.read((char*) (&password), sizeof(password));
                        in.close();

                        adminVector.emplace_back(stoi(temp[1]),temp[2],stoi(temp[0]),
                                                 password);

                    }
                }
            }

        } catch (std::exception& e) {
            std::cerr << e.what() << endl;
        }
    }
};

AdminVector vectorAdmin;

#endif //TRABAJOFINALALESIS_ADMINVECTOR_H
