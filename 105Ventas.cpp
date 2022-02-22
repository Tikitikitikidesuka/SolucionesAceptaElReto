#include <iostream>


using std::string;

typedef float c_float;
typedef std::int_fast16_t c_int;


const string DIAS[6] = {
    "MARTES",
    "MIERCOLES",
    "JUEVES",
    "VIERNES",
    "SABADO",
    "DOMINGO"
};


inline bool semanaInput(c_float semana[6]) {
    c_float input;
    std::cin >> input;

    if(input == -1)
        return false;

    semana[0] = input;
    for(c_int dia = 1; dia < 6; ++dia)
        std::cin >> semana[dia];

    return true;
}

inline c_int semanaMayor(c_float semana[6]) {
    c_int mayorDia = 0;
    c_float mayorValor = semana[0];
    for(c_int dia = 1; dia < 6; ++dia) {
        if(semana[dia] > mayorValor) {
            mayorValor = semana[dia];
            mayorDia = dia;
        }
    }
    return mayorDia;
}

inline c_int semanaMenor(c_float semana[6]) {
    c_int menorDia = 0;
    c_float menorValor = semana[0];
    for(c_int dia = 1; dia < 6; ++dia) {
        if(semana[dia] < menorValor) {
            menorValor = semana[dia];
            menorDia = dia;
        }
    }
    return menorDia;
}

inline c_float semanaMedia(c_float semana[6]) {
    c_float suma = semana[0];
    for(c_int dia = 1; dia < 6; ++dia)
        suma += semana[dia];
    return suma / 6.0;
}


int main() {
    c_float semana[6];
    while(semanaInput(semana)) {
        std::cout << DIAS[semanaMayor(semana)];
        std::cout << " " << DIAS[semanaMenor(semana)];
        std::cout << " " << (semana[5] > semanaMedia(semana) ? "SI" : "NO");
        std::cout << "\n";
    }
    return 0;
}