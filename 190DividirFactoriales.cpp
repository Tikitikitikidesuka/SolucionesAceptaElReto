#include <iostream>


typedef std::uint_fast64_t c_int_big;
typedef std::uint_fast16_t c_int_small;


inline void fastIntInput(c_int_small& number) {
    register std::int_fast8_t input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
}

inline void fastOutput(c_int_big x){
    std::int_fast8_t buffer[19];
    register std::int_fast8_t i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
        putchar_unlocked('\n');
}


inline c_int_big divFact(c_int_small big, c_int_small small) {
    c_int_big result = 1;
    while(big > small)
        result *= big--;
    return result;
}


int main() {
    c_int_small num, den;
    fastIntInput(num);
    fastIntInput(den);
    while(num >= den) {
        fastOutput(divFact(num, den));
        
        fastIntInput(num);
        fastIntInput(den);
    }

    return 0;
}