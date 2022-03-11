#include <iostream>


typedef int_fast8_t c_char;
typedef int_fast8_t c_bool;
typedef int_fast16_t c_int;


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


const c_char vocales[5] = {'a', 'e', 'i', 'o', 'u'};


inline void updateVocales(c_char letra, c_bool boolVocales[5]) {
    for(c_int it = 0; it < 5; ++it) {
        if(letra == vocales[it])
            boolVocales[it] = true;
    }
}


int main() {
    c_int words = 0;
    fastIntInput(words);
    
    while(words--) {
        c_char input = getchar_unlocked();
        // Vaciar buffer de caracteres no letras
        while(input <= ' ') input = getchar_unlocked();

        c_bool boolVocales[5] = {false,false,false,false,false};
        while(input > ' ') {
            updateVocales(input, boolVocales);
            input = getchar_unlocked();
        }

        c_bool pentavoltaica = true;
        for(c_int it = 0; pentavoltaica && it < 5; ++it)
            pentavoltaica = boolVocales[it];

        if(pentavoltaica) {
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