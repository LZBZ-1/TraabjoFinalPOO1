cmake_minimum_required(VERSION 3.22)
project(TrabajoFinalAlesis)

set(CMAKE_CXX_STANDARD 11)

add_executable(TrabajoFinalAlesis main.cpp Clases/Persona/Persona.h Clases/Persona/Cliente.h Clases/Encriptacion/Base64.h Clases/Persona/Cajero.h Clases/Persona/Admin.h Clases/Funciones.h Controlador/ClienteVector/ClienteVector.h Controlador/AdminVector/AdminVector.h)
add_executable(Prueba prueba.cpp Clases/Persona/Persona.h Clases/Persona/Cliente.h Clases/Encriptacion/Base64.h Clases/Persona/Cajero.h Clases/Persona/Admin.h Clases/Funciones.h Controlador/ClienteVector/ClienteVector.h Clases/Conversores.h Controlador/CajeroVector/CajeroVector.h Controlador/AdminVector/AdminVector.h Clases/Encriptacion/Password.h)