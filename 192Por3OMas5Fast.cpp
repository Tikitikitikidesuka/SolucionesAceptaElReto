#include <iostream>


bool fastInput(int* number) {
    register int input;
 
    *number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        *number = *number * 10 + input - 48;

    return *number != 0;
}


inline void printNo() {
    putchar_unlocked('N');
    putchar_unlocked('O');
}

inline void printSi() {
    putchar_unlocked('S');
    putchar_unlocked('I');
}


const int results[22] = {true, false, true, false, false, true, false, true, true, false,true,
                         false, true, true, false, true, false, true, true, false, true, false};
// A partir del 23 es true menos los múltiplos de 5



int main() {
    int input;
    while(fastInput(&input)) {
        if(input < 23) {
            if(results[input - 1])
                printSi();
            else
                printNo();
        } else {
            if(input % 5 == 0) 
                printNo();
            else
                printSi();
        }
        putchar_unlocked('\n');
    }
    return 0;
}