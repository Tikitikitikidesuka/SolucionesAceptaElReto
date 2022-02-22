#include <iostream>
#include <math.h>


typedef float c_float;
typedef std::int_fast16_t c_int;


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
    std::cin >> grado;
    while(grado != 20) {
        c_int precision;
        c_int coeficientes[20];

        for(c_int coefIt = grado; coefIt >= 0; --coefIt)
            std::cin >> coeficientes[coefIt];
        std::cin >> precision;

        c_float result = 0;
        c_float invPrec = 1 / (c_float) precision;
        for(c_int xIt = 0; xIt < precision; ++xIt) {
            c_float funcRes = calcularFunc(invPrec * xIt, grado, coeficientes);
            if(funcRes > 1)
                result += invPrec;
            else if(funcRes > 0)
                result += invPrec * funcRes;
        }

        if(1 - result * 2 < -DIFF_JUSTO) {
            std::cout << "CAIN";
        } else if(1 - result * 2 > DIFF_JUSTO) {
            std::cout << "ABEL";
        } else {
            std::cout << "JUSTO";
        }
        std::cout << "\n";
        
        std::cin >> grado;
    }
}