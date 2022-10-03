#include "Clases/Funciones.h"

using namespace std;

bool isAdmin = false;

void init();
bool ingresoSistema();
void menuOpciones();
void menu();
void generarVenta(){}
void listarCliente(){}
void listarCajero(){}
void listarProductos(){}
void eliminarCliente(){}
void eliminarCajero(){}
void eliminarProducto(){}



int main() {
    int intentos;
    init();

    while(!ingresoSistema() && intentos <= 3){
        system("cls");
        intentos++;
    }

    while (1){
        menu();
    }

}

void init(){
    cargarDatorAdmin();
    cargarDatorCajero();
    cargarDatorCliente();
}

bool ingresoSistema(){
    int id;
    Password password;

    if(vectorAdmin.isVacio()){
        registarAdmin();
        registarCajero();
    }

    system("cls");
    cout << "Ingrese al sistema: " << endl;
    cout << "Ingrese su id: " ;
    cin >> id;
    cout << "Ingrese su contrasena: " ;
    cin >> password.password;

    if(vectorAdmin.buscarPorId(id).getId() == id && vectorAdmin.buscarPorId(id).getPassword().password == base64::Cifrar(password.password)){
        isAdmin = true;
        cout << "Acceso Concedido" << endl;
        system("PAUSE");
        return true;
    } else if (vectorCajero.buscarPorId(id).getId() == id && vectorAdmin.buscarPorId(id).getPassword().password == base64::Cifrar(password.password)){
        cout << "Acceso Concedido" << endl;
        system("PAUSE");
        return true;
    }

    cout << "Acceso denegado. Intentelo otra vez." << endl;
    system("Pause");
    return false;
}

void menuOpciones(){
    string option;
    system("cls");
    cout << "Opciones disponibles\n";
    cout << "1. Listar Cliente\n";
    cout << "2. Quitar Cliente\n";
    cout << "3. Listar Cajeros\n";
    cout << "4. Quitar Cajeros\n";
    cout << "5. Agregar Productos\n";
    cout << "6. Quitar productos\n";
    cout << "7. Salir";
    cout << "\nIngrese una opncion valida[1-7]: ";

    cin >> option;


    if (option == "1"){
        listarCliente();
    } else if(option == "2"){
        eliminarCliente();
    } else if(option == "3"){
        listarCajero();
    } else if(option == "4") {
        eliminarCajero();
    } else if(option == "5") {
        listarProductos();
    } else if(option == "6") {
        exit(0);
    } else if(option == "7") {
        menu();
    } else{
        cout << "Ingrese una opcion correcta\n";
        system("PAUSE");
        menuOpciones();
    }
}

void menu(){
    string option;
    system("cls");
    cout << "Menu de opciones:\n";
    cout << "1. Generar Venta.\n";
    cout << "2. Mas opciones.";
    cout << "3. Salir";
    cout << "\nIngrese una opncion valida[1-3]: ";

    cin >> option;

    if (option == "1"){
        generarVenta();
    } else if(option == "2"){
        menuOpciones();
    } else if(option == "3"){
        exit(0);
    } else{
        cout << "Ingrese una opcion correcta\n";
        system("PAUSE");
        menu();
    }


};