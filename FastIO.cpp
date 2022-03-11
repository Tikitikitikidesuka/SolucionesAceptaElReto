#include <iostream>


// Easy fast I/O for cin and cout
std::cin.tie(NULL);
std::ios_base::sync_with_stdio(false);


// Requiere iostream
// Devuelve el siguiente entero de stdin
inline void fastIntInput(int& number) {
    register bool negativo = false;
    register std::int_fast8_t  input;
 
    // Clear noise on buffer
    for (; (input < '0' || input > '9') && input != '-'; input = getchar_unlocked());
    
    if (input == '-') {
        negativo = true;
        input = getchar_unlocked();
    }

    number = 0;
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
    
    if(negativo)
        number *= -1;
}


// Requiere iostream
// Devuelve el siguiente entero de stdin
// Devuelve false si se ha alcanzado el final del input
inline bool fastIntInputCheckEnd(int& number) {
    register bool negativo = false;
    register std::int_fast8_t  input;
 
    // Clear noise on buffer
    for (; (input < '0' || input > '9') && input != '-'; input = getchar_unlocked())
        if(input == EOF) return false;
    
    if (input == '-') {
        negativo = true;
        input = getchar_unlocked();
    }

    number = 0;
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
    
    if(negativo)
        number *= -1;

    return true;
}


// Requiere iostream
// Devuelve el siguiente int positivo de stdin
inline void fastPositiveInputNoisyStdin(int& number) {
    register std::int_fast8_t input;
 
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
inline bool fastPositiveIntInputCheckEnd(int& number) {
    register std::int_fast8_t  input;
 
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
    register std::int_fast8_t inputChar;
 
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
// Guarda el siguiente digito (negativo o positivo)
// Devuelve true si se ha recogido un digito, false si habia cambio de linea / EOF
inline bool fastDigitInput(char& number) {
    register std::int_fast8_t input;
    register std::int_fast8_t negativo = false;

    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9') && input != '-'; input = getchar_unlocked())
        if(input < ' ' || input == EOF) return false;
    
    // Check if negative
    if(input == '-') {
        negativo = true;
        input = getchar_unlocked();
    }

    number = input - '0';
    if(negativo) number *= -1;

    return true;
}


// Requiere iostream
// Devuelve el siguiente digito
inline void fastPositiveDigitInput(char& number) {
    register std::int_fast8_t input;
 
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
    number = input - '0';
}


// Requiere iostream
// Imprime un int positivo
inline void fastIntOutput(int x){
    std::int_fast8_t negative = x < 0;
    if(x < 0) {
        putchar_unlocked('-');
        negative = true;
        x *= -1;
    }

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


// Requiere iostream
// Imprime un int positivo
inline void fastPositiveIntOutput(int x){
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