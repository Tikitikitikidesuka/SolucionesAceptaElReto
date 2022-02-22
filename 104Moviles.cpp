#include <iostream>


typedef std::int_fast16_t c_int;


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


c_int esMovilEstable(bool& estable, bool& terminado) {
    if(terminado)
        return -1;

    c_int p1, p2, d1, d2;
    fastIntInput(p1);
    fastIntInput(d1);
    fastIntInput(p2);
    fastIntInput(d2);

    if(p1 == 0 && d1 == 0 && p2 == 0 && d2 == 0)
        terminado = true;

    if(!terminado && !p1)
        p1 = esMovilEstable(estable, terminado);
    if(!terminado && !p2)
        p2 = esMovilEstable(estable, terminado);

    if(!terminado && estable && p1 * d1 != p2 * d2)
        estable = false;

    if(terminado)
        return -1;

    return p1 + p2;
}

c_int esMovilEstable(bool& estable) {
    estable = true;
    bool terminado = false;
    esMovilEstable(estable, terminado);
    if(terminado)
        return -1;
    return 1;
}


int main() {
    bool estable = true;
    while(esMovilEstable(estable) != -1) {
        if(estable) {
            putchar_unlocked('S');
            putchar_unlocked('I');
        } else {
            putchar_unlocked('N');
            putchar_unlocked('O');
        }
        putchar_unlocked('\n');
    }
    return 0;
}