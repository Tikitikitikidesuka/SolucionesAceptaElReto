#include <iostream>


typedef std::int_fast16_t c_int_big;
typedef std::int_fast8_t c_int_small;


inline bool fastDigitInput(c_int_small& number) {
    register std::int_fast8_t input;
    register std::int_fast8_t negativo = false;

    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9') && input != '-'; input = getchar_unlocked())
        if(input < ' ' || input == EOF) return false;
    
    // Check if negative
    if(input == '-') {
        negativo = true;
        input = getchar_unlocked();
    }

    number = input - '0';
    if(negativo) number *= -1;

    return true;
}

inline void fastOutput(c_int_big x){
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


int main() {
    c_int_small digit = 1;
    fastDigitInput(digit);
    c_int_big suma = digit;
    while(digit >= 0) {
        putchar_unlocked(digit + '0');

        while(fastDigitInput(digit)) {
            suma += digit;
            putchar_unlocked(' ');
            putchar_unlocked('+');
            putchar_unlocked(' ');
            putchar_unlocked(digit + '0');
        }
        putchar_unlocked(' ');
        putchar_unlocked('=');
        putchar_unlocked(' ');
        fastOutput(suma);

        fastDigitInput(digit);
        suma = digit;
    }

    return 0;
}