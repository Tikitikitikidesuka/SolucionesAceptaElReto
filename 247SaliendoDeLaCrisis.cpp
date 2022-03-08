#include <iostream>


typedef std::uint_fast8_t c_bool;
typedef std::uint_fast16_t c_int;


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

inline void ignoreIntInput() {
    register std::int_fast8_t input;
 
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked());
}


int main() {
    register c_int casos;
    fastIntInput(casos);
    while(casos) {
        register c_int prev = 0;
        register c_bool creciente = true;
        while(creciente && casos) {
            register c_int input;
            fastIntInput(input);
            creciente = prev < input;
            prev = input;

            --casos;
        }

        if(casos) {
            while(getchar_unlocked() != '\n');
        }

        if(creciente) {
            putchar_unlocked('S');
            putchar_unlocked('I');
        } else {
            putchar_unlocked('N');
            putchar_unlocked('O');
        }
        putchar_unlocked('\n');

        fastIntInput(casos);
    }

    return 0;
}