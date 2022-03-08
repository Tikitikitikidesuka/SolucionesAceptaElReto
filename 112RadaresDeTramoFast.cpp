#include <iostream>


typedef std::int_fast16_t c_int;


inline void fastIntInput(c_int& number) {
    register std::int_fast8_t negativo = false;
    register std::int_fast8_t input;
 
    // Clear noise on buffer
    for (; (input < '0' || input > '9') && input != '-'; input = getchar_unlocked());
    
    if (input == '-') {
        negativo = true;
        input = getchar_unlocked();
    }

    number = 0;
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - '0';
    
    if(negativo)
        number *= -1;
}

inline void fastPrintError() {
    putchar_unlocked('E');
    putchar_unlocked('R');
    putchar_unlocked('R');
    putchar_unlocked('O');
    putchar_unlocked('R');
}

inline void fastPrintPuntos() {
    putchar_unlocked('P');
    putchar_unlocked('U');
    putchar_unlocked('N');
    putchar_unlocked('T');
    putchar_unlocked('O');
    putchar_unlocked('S');
}

inline void fastPrintMulta() {
    putchar_unlocked('M');
    putchar_unlocked('U');
    putchar_unlocked('L');
    putchar_unlocked('T');
    putchar_unlocked('A');
}

inline void fastPrintOk() {
    putchar_unlocked('O');
    putchar_unlocked('K');
}


int main() {
    //   metros  km/h   segundos
    c_int dist, maxVel, tiempo;
    fastIntInput(dist);
    fastIntInput(maxVel);
    fastIntInput(tiempo);
    while(dist != 0 || maxVel != 0 || tiempo != 0) {
        if(dist <= 0 || maxVel <= 0 || tiempo <= 0) {
            fastPrintError();
        } else {
            c_int velocidad_t10 = dist * 36 / tiempo;
            if(velocidad_t10 > maxVel * 10) {
                if(velocidad_t10 > maxVel * 12) {
                    fastPrintPuntos();
                } else {
                    fastPrintMulta();
                }
            } else {
                fastPrintOk();
            }
        }
        putchar_unlocked('\n');

        fastIntInput(dist);
        fastIntInput(maxVel);
        fastIntInput(tiempo);
    }

    return 0;
}