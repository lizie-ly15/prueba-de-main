#include <iostream>
#include <fstream>

using namespace std;


void mostrarGanadores() {
    ifstream archivo("ganadores.txt", ios::app); // Abrir archivo en modo lectura
    if (archivo.is_open()) {
        string nombre;
        cout << "--------------------" << endl;
        cout << "Lista de Ganadores:" << endl;
        while (getline(archivo, nombre)) {
            cout << nombre << endl;
        }
        archivo.close();
        cout << "--------------------" << endl;
    } else {
        cout << "No se pudo abrir el archivo de ganadores." << endl;
    }
}