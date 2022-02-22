#include <iostream>
#include <math.h>


typedef float c_float;
typedef std::int_fast16_t c_int;


inline void fastIntInput(c_int& number) {
    register bool negativo = false;
    register std::int_fast8_t  input;
 
    // Clear noise on buffer
    for (; (input < '0' || input > '9') && input != '-'; input = getchar_unlocked());
    
    if (input == '-') {
        negativo = true;
        input = getchar_unlocked();
    }

    number = 0;
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
    
    if(negativo)
        number *= -1;
}


inline void printCain() {
    putchar_unlocked('C');
    putchar_unlocked('A');
    putchar_unlocked('I');
    putchar_unlocked('N');
}

inline void printAbel() {
    putchar_unlocked('A');
    putchar_unlocked('B');
    putchar_unlocked('E');
    putchar_unlocked('L');
}

inline void printJusto() {
    putchar_unlocked('J');
    putchar_unlocked('U');
    putchar_unlocked('S');
    putchar_unlocked('T');
    putchar_unlocked('O');
}


inline c_float calcularFunc(c_float x, c_int grado, c_int coeficientes[20]) {
    c_float power = x; // power = x^1
    c_float result = coeficientes[0];
    for(c_int coefIt = 1; coefIt <= grado; ++coefIt) {
        result += coeficientes[coefIt] * power;
        power *= x;

        // Implementacion antigua calculaba varias veces la misma potencia
        /*if(coeficientes[coefIt] != 0)
            result += coeficientes[coefIt] * pow(x, coefIt);*/
    }
    return result;
}


const c_float DIFF_JUSTO = 0.001;


int main() {
    c_int grado;
    fastIntInput(grado);
    while(grado != 20) {
        c_int precision;
        c_int coeficientes[20];

        for(c_int coefIt = grado; coefIt >= 0; --coefIt)
            fastIntInput(coeficientes[coefIt]);
        fastIntInput(precision);

        c_float result = 0;
        c_float invPrec = 1 / (c_float) precision;
        for(c_int xIt = 0; xIt < precision; ++xIt) {
            c_float funcRes = calcularFunc(invPrec * xIt, grado, coeficientes);
            if(funcRes > 1)
                result += invPrec * 1;
            else if(funcRes > 0)
                result += invPrec * calcularFunc(invPrec * xIt, grado, coeficientes);
        }

        if(1 - result * 2 < -DIFF_JUSTO)
            printCain();
        else if(1 - result * 2 > DIFF_JUSTO)
            printAbel();
        else 
            printJusto();
        putchar_unlocked('\n');
        
        fastIntInput(grado);
    }

    return 0;
}