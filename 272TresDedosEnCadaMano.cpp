#include <iostream>


typedef uint_fast32_t c_int;

inline void fastIntInput(c_int& number) {
    register std::uint_fast8_t input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
}

inline void printBaseSix(c_int num) {
    std::uint_fast8_t index = 7;
    std::uint_fast8_t output[8];
    while(num != 0) {
        output[index--] = num % 6 + '0';
        num /= 6;
    }
    if(index == 7) {
        putchar_unlocked('0');
    } else {
        for(++index; index < 8; ++index)
            putchar_unlocked(output[index]);
    }
}


int main() {
    c_int casos;
    fastIntInput(casos);
    while(casos--) {
        c_int num;
        fastIntInput(num);
        printBaseSix(num);
        putchar_unlocked('\n');
    }
    return 0;
}