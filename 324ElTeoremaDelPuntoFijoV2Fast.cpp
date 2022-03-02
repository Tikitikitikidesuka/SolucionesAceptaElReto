#include <iostream>


#define MAX_SIZE 100


typedef std::int_fast8_t c_bool;
typedef std::int_fast32_t c_int;


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

inline void fastIntOutput(c_int x){
    std::int_fast8_t buffer[35];
    register std::int_fast8_t i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
        putchar_unlocked('\n');
}


inline void desplazamiento(c_int size, c_int inputs[MAX_SIZE], c_int desplazamientos[MAX_SIZE]) {
    for(c_int it = 0; it < size; ++it) {
        c_int disp = it + 1 - inputs[it];
        if(disp < 0) disp += size;
        desplazamientos[inputs[it]-1] = disp;
    }
}

inline c_int getPeriodo(c_int pos, c_int size, c_int desplazamientos[MAX_SIZE], c_bool repetidos[MAX_SIZE]) {
    c_int periodo = 1;
    c_int movPos = pos + desplazamientos[pos];
    repetidos[pos] = repetidos[movPos] = true;
    if(movPos >= size) movPos -= size;
    while(movPos != pos) {
        repetidos[movPos] = true;
        movPos += desplazamientos[movPos];
        if(movPos >= size) movPos -= size;
        ++periodo;
    }

    return periodo;
}

inline c_int gcd(c_int a, c_int b) {
    c_int swap;
    while (b != 0) {
        swap = a % b;

        a = b;
        b = swap;
    }
    return a;
}

inline c_int lcm(c_int a, c_int b) {
    return a  / gcd(a, b) * b;
}


int main() {
    c_int longitud;
    fastIntInput(longitud);
    while(longitud != 0) {
        c_int inputs[MAX_SIZE];
        for(c_int it = 0; it < longitud; ++it)
            fastIntInput(inputs[it]);

        c_int desplazamientos[MAX_SIZE];
        desplazamiento(longitud, inputs, desplazamientos);

        c_bool repetidos[MAX_SIZE] = {0};
        c_int lcmResult = getPeriodo(0, longitud, desplazamientos, repetidos);
        for(c_int it = 1; it < longitud; ++it) {
            if(!repetidos[it])
                lcmResult = lcm(lcmResult, getPeriodo(it, longitud, desplazamientos, repetidos));
        }

        fastIntOutput(lcmResult);

        fastIntInput(longitud);
    }

    return 0;
}