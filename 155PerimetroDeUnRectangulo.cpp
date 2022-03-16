#include <iostream>


typedef std::int_fast32_t c_int;


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

inline void fastIntOutput(c_int x){
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


int main() {
    c_int base, altura;
    fastIntInput(base);
    fastIntInput(altura);

    while(base >= 0 && altura >= 0) {
        c_int perimetro = 2 * (base + altura);
        fastIntOutput(perimetro);

        fastIntInput(base);
        fastIntInput(altura);
    }

    return 0;
}