#include <iostream>


typedef std::uint_fast32_t c_int;


inline bool fastIntInput(c_int& number) {
    register bool status = true;
    register std::int_fast8_t  input;
 
    // Clear noise on buffer
    for (; (input < '0' || input > '9') && input != '-'; input = getchar_unlocked());
    
    if (input == '-') {
        status = false;
        input = getchar_unlocked();
    }

    number = 0;
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
    
    return status;
}


int main() {
    c_int p, n;
    while(fastIntInput(p) + fastIntInput(n)) {
        if(p <= n || p == 1) {
            putchar_unlocked('Y');
            putchar_unlocked('E');
            putchar_unlocked('S');
        } else {
            putchar_unlocked('N');
            putchar_unlocked('O');
        }
        putchar_unlocked('\n');
    }
    return 0;
}