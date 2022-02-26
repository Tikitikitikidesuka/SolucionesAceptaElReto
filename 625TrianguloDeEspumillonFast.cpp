#include <algorithm>
#include <iostream>


#define MAX_LADOS 3000


using std::sort;
typedef std::int_fast8_t c_bool;
typedef std::int_fast32_t c_int;


inline void fastPositiveInput(c_int& number) {
    register std::int_fast8_t input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
}

inline void fastOutput(c_int x){
    std::int_fast8_t buffer[9];
    register std::int_fast8_t i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
        putchar_unlocked('\n');
}

inline void printNoExiste() {
    putchar_unlocked('N');
    putchar_unlocked('O');
    putchar_unlocked(' ');
    putchar_unlocked('H');
    putchar_unlocked('A');
    putchar_unlocked('Y');
    putchar_unlocked(' ');
    putchar_unlocked('N');
    putchar_unlocked('I');
    putchar_unlocked('N');
    putchar_unlocked('G');
    putchar_unlocked('U');
    putchar_unlocked('N');
    putchar_unlocked('O');
    putchar_unlocked('\n');
}


/** Se basa en el teorema de la desigualdad triangular:
 *      La suma de dos lados cualesquiera de un triangulo siempre
 *      sera mayor que la longitud del restante.
 * 
 *  Esta funcion asume que los lados se van a introducir en orden decreciente,
 *  por lo que solo comprueba que a < b + c.
 */
inline c_bool ladosFormanTrianguloSorted(c_int a, c_int b, c_int c) {
    return a < b + c;
}


int main() {
    c_int casos;
    fastPositiveInput(casos);

    while(casos--) {
        c_int numLados;
        fastPositiveInput(numLados);

        c_int lados[MAX_LADOS];
        for(c_int ladoIt = 0; ladoIt < numLados; ++ladoIt) {
            fastPositiveInput(lados[ladoIt]);
        }

        sort(lados, lados + numLados, std::greater<c_int>());

        c_bool encontrado = false;
        c_int perimetro, usados = 0;
        while(usados < numLados - 2 && !encontrado) {
            if(ladosFormanTrianguloSorted(lados[usados], lados[usados+1], lados[usados+2])) {
                perimetro = lados[usados] + lados[usados+1] + lados[usados+2];
                encontrado = true;
            }
            ++usados;
        }

        if(encontrado)
            fastOutput(perimetro);
        else {
            printNoExiste();
        }
    }

    return 0;
}