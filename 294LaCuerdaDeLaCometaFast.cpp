#include <iostream>


#define MAX_INPUT 1000


typedef std::int_fast64_t c_int;
const c_int C_INT_MAX = INT64_MAX;


inline void fastIntInput(c_int& number) {
    register std::int_fast8_t input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - '0';
}

inline bool fastIntInputCheckEnd(c_int& number) {
    register std::int_fast8_t input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked())
        if(input == EOF) return false;
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - '0';
    
    return true;
}

inline void fastIntOutput(c_int x){
    std::int_fast8_t buffer[20];
    register std::int_fast8_t i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
}


c_int numFormas(c_int longitud, c_int numCuerdas, c_int longitudCuerdas[MAX_INPUT]) {
    c_int mat[2][MAX_INPUT + 1];

    for(int it = 1; it <= longitud; ++it)
        mat[0][it] = 0;
    
    for(int it = 0; it <= numCuerdas; ++it)
        mat[it%2][0] = 1;
    
    for(int it = 1; it <= numCuerdas; ++it) {
        for(int l = 1; l <= longitud; ++l) {
            mat[it%2][l] = mat[(it-1)%2][l];
            if(l - longitudCuerdas[it-1] >= 0)
                mat[it%2][l] += mat[(it-1)%2][l - longitudCuerdas[it-1]];
        }
    }

    return mat[numCuerdas%2][longitud];
}

c_int minCuerdas(c_int longitud, c_int numCuerdas, c_int longitudCuerdas[MAX_INPUT]) {
        c_int mat[2][MAX_INPUT + 1];

        for(c_int it = 1; it <= longitud; ++it)
            mat[0][it] = C_INT_MAX;

        for(c_int it = 0; it <= numCuerdas; ++it)
            mat[it%2][0] = 0;

        for(c_int it = 1; it <= numCuerdas; ++it) {
            for(c_int l = 1; l <= longitud; ++l) {
                if(l - longitudCuerdas[it-1] >= 0 && mat[(it-1)%2][l - longitudCuerdas[it-1]] < C_INT_MAX) {
                    mat[it%2][l] = std::min(mat[(it-1)%2][l], 1 + mat[(it-1)%2][l - longitudCuerdas[it-1]]);
                } else {
                    mat[it%2][l] = mat[(it-1)%2][l];
                }
            }
        }

        return mat[numCuerdas%2][longitud];
    }

c_int costeMinimo(c_int longitud, c_int numCuerdas, c_int longitudCuerdas[MAX_INPUT], c_int costeCuerdas[MAX_INPUT]) {
        c_int mat[2][MAX_INPUT + 1];

        for(c_int it = 1; it <= longitud; ++it)
            mat[0][it] = C_INT_MAX;

        for(c_int it = 0; it <= numCuerdas; ++it)
            mat[it%2][0] = 0;

        for(c_int it = 1; it <= numCuerdas; ++it) {
            for(c_int l = 1; l <= longitud; ++l) {
                if(l - longitudCuerdas[it-1] >= 0 && mat[(it-1)%2][l - longitudCuerdas[it-1]] < C_INT_MAX) {
                    mat[it%2][l] = std::min(mat[(it-1)%2][l], costeCuerdas[it-1] + mat[(it-1)%2][l - longitudCuerdas[it-1]]);
                } else {
                    mat[it%2][l] = mat[(it-1)%2][l];
                }
            }
        }

        return mat[numCuerdas%2][longitud];
    }


int main() {
    c_int cuerdas, objetivo;
    while(fastIntInputCheckEnd(cuerdas)) {
        fastIntInput(objetivo);
        c_int longCuerdas[MAX_INPUT];
        c_int costCuerdas[MAX_INPUT];

        for(std::int_fast16_t cuerda = 0; cuerda < cuerdas; ++cuerda) {
            fastIntInput(longCuerdas[cuerda]);
            fastIntInput(costCuerdas[cuerda]);
        }

        c_int formas = numFormas(objetivo, cuerdas, longCuerdas);
        if(formas > 0) {
            putchar_unlocked('S');
            putchar_unlocked('I');
            putchar_unlocked(' ');

            fastIntOutput(formas);
            putchar_unlocked(' ');
            
            fastIntOutput(minCuerdas(objetivo, cuerdas, longCuerdas));
            putchar_unlocked(' ');

            fastIntOutput(costeMinimo(objetivo, cuerdas, longCuerdas, costCuerdas));
        } else {
            putchar_unlocked('N');
            putchar_unlocked('O');
        }
        putchar_unlocked('\n');
    }

    return 0;
}