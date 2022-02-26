#include <stdio.h>
#include <inttypes.h>


#define MAX_JUGADORES 262144


typedef int_fast8_t c_bool;
typedef int_fast8_t c_char;
typedef int_fast16_t c_int;


inline void fastIntInput(c_int* number) {
    register int_fast8_t  input;
 
    *number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        *number = *number * 10 + input - 48;
}

inline void fastOutput(c_int x){
    int_fast8_t buffer[18];
    register c_int i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    --i;
    while(i >= 0) putchar_unlocked(buffer[i--]);
        putchar_unlocked('\n');
}


inline c_int pow2(c_int exp) {
    if(exp == 0)
        return 1;
    return 2 << (exp - 1);
}


int main() {
    c_bool estado[MAX_JUGADORES];

    c_int jugadores, rondas;
    fastIntInput(&jugadores);
    fastIntInput(&rondas);

    while(jugadores != 0 || rondas != 0) {
        register c_int jugador;
        if(rondas > 0) {
            for(jugador = 0; jugador < jugadores; ++jugador)
                estado[jugador] = getchar_unlocked() - '0';

            register c_int disp = 1, ddisp;
            register c_int partidos = 0;
            register c_int rondaIt;
            for(rondaIt = 0; rondaIt < rondas && disp < jugadores; ++rondaIt) {
                disp = pow2(rondaIt);
                ddisp = disp << 1;
                for(jugador = 0; jugador < jugadores; jugador += ddisp) {
                    partidos += estado[jugador] && estado[jugador + disp];
                    estado[jugador] = estado[jugador] || estado[jugador + disp];
                }
            }

            fastOutput(partidos);
        } else {
            while(jugadores--) getchar_unlocked();
            putchar_unlocked('0');
            putchar_unlocked('\n');
        }

        fastIntInput(&jugadores);
        fastIntInput(&rondas);
    }

    return 0;
}