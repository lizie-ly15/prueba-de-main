#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

void mostrarJugadores() {
    ifstream archivo("jugadores.txt", ios::app); // Abrir archivo en modo lectura
    if (archivo.is_open()) {
        string nombre;
        cout << "--------------------" << endl;
        cout << "Lista de Jugadores:" << endl;
        while (getline(archivo, nombre)) {
            cout << nombre << endl;
        }
        archivo.close();
        cout << "--------------------" << endl;
    } else {
        cout << "No se pudo abrir el archivo de jugadores." << endl;
    }
}