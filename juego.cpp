#include <iostream> 
#include <string>
#include <cctype> 
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_LETRAS = 26;
const int NUM_PALABRAS_FACIL = 5;
const int NUM_PALABRAS_INTERMEDIO = 5;
const int NUM_PALABRAS_DIFICIL = 5;

const string PALABRAS_FACIL[NUM_PALABRAS_FACIL] = {
    "hola", "casa", "gato", "lago", "hijo"
};

const string PALABRAS_INTERMEDIO[NUM_PALABRAS_INTERMEDIO] = {
    "pantalla", "internet", "programa", "historia", "herencia"
};

const string PALABRAS_DIFICIL[NUM_PALABRAS_DIFICIL] = {
    "programacion", "polimorfismo", "computadora", "constitucion", "experiencias"
};

void mostrarEstado(const string palabraOculta, const char letrasIncorrectas[], int Vidas) {
    cout << "Palabra: " << palabraOculta << "\n";
    cout << "Letras incorrectas: ";
    for (int i = 0; i < MAX_LETRAS; i++) {
        if (letrasIncorrectas[i] != '\0') {
            cout << letrasIncorrectas[i] << " ";
        }
    }
    cout << "\nIntentos restantes: " << Vidas << "\n";
}

bool letraYaIngresada(char letra, const char letras[], int tamano) {
    for (int i = 0; i < tamano; i++) {
        if (letras[i] == letra) {
            return true;
        }
    }
    return false;
}

string obtenerPalabra(int nivel) {
    srand(static_cast<unsigned int>(time(0)));
    int indice;
    
    switch (nivel) {
        case 1:
            indice = rand() % NUM_PALABRAS_FACIL;
            return PALABRAS_FACIL[indice];
        case 2:
            indice = rand() % NUM_PALABRAS_INTERMEDIO;
            return PALABRAS_INTERMEDIO[indice];
        case 3:
            indice = rand() % NUM_PALABRAS_DIFICIL;
            return PALABRAS_DIFICIL[indice];
        default:
            return "Error"; // Manejar caso de error
    }
}

void jugarAhorcado(int nivel) {
    string palabra = obtenerPalabra(nivel);
    string palabraOculta(palabra.size(), '_');
    char letrasIncorrectas[MAX_LETRAS] = {};
    char letrasCorrectas[MAX_LETRAS] = {};
    int numIncorrectas = 0, numCorrectas = 0, Vidas = 5;
    char letra;
    string nombre;
    
    
    cout << "Ingrese un nombre: \n"; 
    cin >> nombre; 

    cout << "Hola " << nombre << ". La palabra a adivinar tiene " << palabra.size() << " letras." << endl;

    while (Vidas > 0 && palabraOculta != palabra) {
        mostrarEstado(palabraOculta, letrasIncorrectas, Vidas);
        cout << "Ingrese una letra: ";
        cin >> letra;
        
        // Convertir la letra a minúscula
        letra = tolower(letra);

        // Validar que se ingresa una letra
        if (!isalpha(letra)) {
            cout << "Por favor, ingrese una letra válida.\n";
            continue;
        }

        if (letraYaIngresada(letra, letrasCorrectas, numCorrectas) ||
            letraYaIngresada(letra, letrasIncorrectas, numIncorrectas)) {
            cout << "Ya has ingresado esa letra. Intenta con otra.\n";
            continue;
        }

        bool acierto = false;
        for (size_t i = 0; i < palabra.size(); i++) {
            if (tolower(palabra[i]) == letra) {
                palabraOculta[i] = palabra[i];
                acierto = true;
            }
        }

        if (acierto) {
            letrasCorrectas[numCorrectas++] = letra;
        } else {
            letrasIncorrectas[numIncorrectas++] = letra;
            Vidas--;
        }
    }
    
    if (palabraOculta == palabra) {
        cout << "¡Felicidades! Has adivinado la palabra: " << palabra << "\n";
    } else {
        cout << "Lo siento, te has quedado sin intentos. La palabra era: " << palabra << "\n";
    }
}

int main (){
    
 int nivel;

    do {
        cout << "Selecciona el nivel de dificultad:\n";
        cout << "1. Fácil \n";
        cout << "2. Intermedio \n";
        cout << "3. Difícil \n";
        cout << "Elige una opción (1-3): ";
        cin >> nivel;

        if (nivel < 1 || nivel > 3) {
            cout << "Opción no válida. Por favor, elige un número entre 1 y 3.\n";
        }
    } while (nivel < 1 || nivel > 3);

    jugarAhorcado(nivel);

    return 0;
}