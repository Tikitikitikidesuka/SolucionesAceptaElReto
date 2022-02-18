#include <iostream>


typedef std::int_fast64_t c_int;


inline void fastIntInput(c_int& number) {
    register char input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
}

inline void fastOutput(c_int x){
    char buffer[13];
    register int i=0;
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
    fastIntInput(casos);
    while(casos--) {
        c_int num;
        fastIntInput(num);
        // resultado = a^3 - (a-2)^3
        fastOutput(6*num*(num-2)+8);
    }
    return 0;
}