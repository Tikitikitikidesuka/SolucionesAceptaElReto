#include <iostream>
#include <cstring>


#define MAX_PUNTUACION 1000
#define MAX_CARA_OP 7
#define CARAS_DADO 6


typedef std::int_fast8_t c_bool;
typedef std::int_fast16_t c_int;


inline void fastIntInput(c_int& number) {
    register std::int_fast8_t input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
}


enum GANA_ESTADO {NS, GANA, PIERDE};
GANA_ESTADO ganaBuffer[MAX_PUNTUACION][CARAS_DADO];


c_bool gana(c_int suma, c_int cara);

inline c_bool testGana16(c_int suma) {
    return !gana(suma + 2, 2) || !gana(suma + 3, 3) || !gana(suma + 4, 4) || !gana(suma + 5, 5);
}

inline c_bool testGana25(c_int suma) {
    return !gana(suma + 1, 1) || !gana(suma + 3, 3) || !gana(suma + 4, 4) || !gana(suma + 6, 6);
}

inline c_bool testGana34(c_int suma) {
    return !gana(suma + 1, 1) || !gana(suma + 2, 2) || !gana(suma + 5, 5) || !gana(suma + 6, 6);
}


c_bool gana(c_int suma, c_int cara) {
    // Caso base
    if(suma >= 1000)
        return true;
    
    // Caso almacenado
    if(ganaBuffer[suma][cara] != GANA_ESTADO::NS) {
        return ganaBuffer[suma][cara] == GANA_ESTADO::GANA;
    }

    // Caso recursivo
    c_bool ganaRec;
    switch (cara) {
        case 1:
            ganaRec = testGana16(suma);
            break;
        case 2:
            ganaRec = testGana25(suma);
            break;
        case 3:
            ganaRec = testGana34(suma);
            break;
        case 4:
            ganaRec = testGana34(suma);
            break;
        case 5:
            ganaRec = testGana25(suma);
            break;
        case 6:
            ganaRec = testGana16(suma);
            break;
    }

    if(ganaRec)
        ganaBuffer[suma][cara] = GANA_ESTADO::GANA;
    else
        ganaBuffer[suma][cara] = GANA_ESTADO::PIERDE;

    return ganaRec;
}


int main() {
    std::memset(ganaBuffer, GANA_ESTADO::NS, sizeof ganaBuffer); 

    c_int casos;
    fastIntInput(casos);
    while(casos--) {
        c_int suma, cara;
        fastIntInput(suma);
        fastIntInput(cara);

        if(gana(suma, cara)) {
            putchar_unlocked('G');
            putchar_unlocked('A');
            putchar_unlocked('N');
            putchar_unlocked('A');
        } else {
            putchar_unlocked('P');
            putchar_unlocked('I');
            putchar_unlocked('E');
            putchar_unlocked('R');
            putchar_unlocked('D');
            putchar_unlocked('E');
        }
        putchar_unlocked('\n');
    }

    return 0;
}