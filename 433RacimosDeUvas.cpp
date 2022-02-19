#include <iostream>


typedef std::int_fast32_t c_int;


inline void fastOutput(c_int x){
    char buffer[4];
    register int i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
        putchar_unlocked('\n');
}

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


inline c_int floorSqrt(c_int x) {
    if (x == 0 || x == 1)
    return x;

    c_int i = 1, result = 1;
    while (result <= x) {
      i++;
      result = i * i;
    }
    return i - 1;
}

inline c_int minNivel(c_int uvas) {
    return (1 + floorSqrt(8*uvas)) / 2;
}


int main() {
    c_int input;
    fastIntInput(input);
    while(input != 0) {
        fastOutput(minNivel(input));
        fastIntInput(input);
    }
    return 0;
}