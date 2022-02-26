#include <iostream>


typedef std::int_fast16_t c_int;


inline void fastPositiveInputNoisyStdin(c_int& number) {
    register std::int_fast8_t input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
}

inline void fastPositiveIntOutput(c_int x){
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
    c_int casos;
    fastPositiveInputNoisyStdin(casos);
    while(casos--) {
        c_int a, b;
        fastPositiveInputNoisyStdin(a);
        fastPositiveInputNoisyStdin(b);
        
        fastPositiveIntOutput(a * 100 / (a + b));
    }

    return 0;
}