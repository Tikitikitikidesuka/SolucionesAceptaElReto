#include <iostream>


typedef std::uint_fast32_t c_int;


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


inline void fastIntOutput(c_int x){
    std::int_fast8_t buffer[10];
    register std::int_fast8_t i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
        putchar_unlocked('\n');
}


inline c_int cerosFactorial(c_int num) {
    c_int cincos = 0;

    c_int div5 = num / 5;
    while(div5 > 0) {
        cincos += div5;
        div5 /= 5;
    }

    return cincos;
}


int main() {
    c_int casos;
    fastIntInput(casos);
    while(casos--) {
        c_int input;
        fastIntInput(input);
        fastIntOutput(cerosFactorial(input));
    }

    return 0;
}