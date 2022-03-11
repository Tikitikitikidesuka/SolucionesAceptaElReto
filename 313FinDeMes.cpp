#include <iostream>


typedef std::int_fast16_t c_int;


inline void fastIntInput(c_int& number) {
    register std::int_fast8_t negativo = false;
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


int main() {
    c_int casos;
    fastIntInput(casos);

    while(casos--) {
        c_int inicial, diferencia;
        fastIntInput(inicial);
        fastIntInput(diferencia);
        if(inicial + diferencia >= 0) {
            putchar_unlocked('S');
            putchar_unlocked('I');
        } else {
            putchar_unlocked('N');
            putchar_unlocked('O');
        }
        putchar_unlocked('\n');
    }

    return 0;
}