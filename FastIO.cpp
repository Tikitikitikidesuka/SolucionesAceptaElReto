#include <iostream>


// Requiere iostream
// Devuelve un entero obtenido de stdin
inline void fastInput(int* number) {
    int negative = 0;
    register int input;
 
    *number = 0;
    input = getchar_unlocked();
    if (input == '-') {
        negative = 1;
        input = getchar_unlocked();
    }
 
    for (; (input > 47 && input < 58); input = getchar_unlocked())
        *number = *number * 10 + input - 48;
 
    if (negative)
        *number *= -1;
}


// Requiere iostream
// Devuelve el siguiente int positivo de stdin
inline void fastPositiveInputNoisyStdin(int* number) {
    register int input;
 
    *number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        *number = *number * 10 + input - 48;
}