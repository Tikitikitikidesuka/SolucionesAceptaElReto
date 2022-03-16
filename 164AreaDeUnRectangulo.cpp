#include <iostream>


typedef std::int_fast32_t c_int;


inline void fastIntInput(c_int& number) {
    register std::int_fast8_t negativo = false;
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

inline void fastIntOutput(c_int x){
    std::int_fast8_t buffer[10];
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
    c_int V1X, V1Y, V2X, V2Y;
    fastIntInput(V1X);
    fastIntInput(V1Y);
    fastIntInput(V2X);
    fastIntInput(V2Y);

    while(V1X <= V2X && V1Y <= V2Y) {
        c_int base = V2X - V1X;
        c_int altura = V2Y - V1Y;
        c_int area = base * altura;
        fastIntOutput(area);

        fastIntInput(V1X);
        fastIntInput(V1Y);
        fastIntInput(V2X);
        fastIntInput(V2Y);
    }

    return 0;
}