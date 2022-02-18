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
inline void fastPositiveInputNoisyStdin(int& number) {
    register char input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
}


// Requiere iostream
// Devuelve el siguiente int positivo de stdin
// Devuelve false si se ha alcanzado el final del input
inline bool fastIntInputCheckEnd(int& number) {
    register char input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked())
        if(input == EOF) return false;
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
    
    return true;
}

// Requiere iostream
// Devuelve la siguiente string
inline bool fastStringInput(std::string& inputStr) {
    register char inputChar;
 
    inputStr.clear();
    inputChar = getchar_unlocked();

    // Clear noise on buffer
    for (; (inputChar <= ' '); inputChar = getchar_unlocked())
        if(inputChar == EOF) return false;
 
    // Get number
    for (; (inputChar > ' '); inputChar = getchar_unlocked())
        inputStr += inputChar;

    return true;
}


// Requiere iostream
// Devuelve el siguiente digito
inline void fastDigitInput(char* number) {
    register int input;
 
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
    *number = input - '0';
}


// Requiere iostream
// Imprime un int
inline void fastOutput(int x){
    char buffer[35];
    register int i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
        putchar_unlocked('\n');
}