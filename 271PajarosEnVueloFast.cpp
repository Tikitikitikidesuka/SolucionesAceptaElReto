#include <algorithm>
#include <iostream>
#include <set>


using std::set;
typedef std::int_fast32_t c_int;


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

inline void fastIntOutput(c_int x){
    std::int_fast8_t buffer[35];
    register std::int_fast8_t i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
}


void insertarPareja(set<c_int>& vandada, set<c_int>::iterator& it, c_int val1, c_int val2) {
    vandada.insert(val1);
    vandada.insert(val2);
    if(val1 < *it && val2 < *it)
        --it;
    else if(val1 > *it && val2 > *it)
        ++it;
}


int main() {
    c_int edadInit, parejas;
    fastIntInput(edadInit);
    fastIntInput(parejas);
    while(edadInit != 0 || parejas != 0) {
        set<c_int> vandada;
        vandada.insert(edadInit);

        // Iterador siempre apuntara a la mediana
        c_int medIndex = 1;
        set<c_int>::iterator vandadaIt = vandada.begin();

        // Primera pareja aparte para solucionar el espacio de output
        if(parejas-- > 0) {
            c_int edad1, edad2;
            fastIntInput(edad1);
            fastIntInput(edad2);
            insertarPareja(vandada, vandadaIt, edad1, edad2);
            fastIntOutput(*vandadaIt);
        }
        // Resto de casos se imprimen con espacio
        while(parejas--) {
            c_int edad1, edad2;
            fastIntInput(edad1);
            fastIntInput(edad2);
            insertarPareja(vandada, vandadaIt, edad1, edad2);
            putchar_unlocked(' ');
            fastIntOutput(*vandadaIt);
        }
        putchar_unlocked('\n');

        fastIntInput(edadInit);
        fastIntInput(parejas);
    }

    return 0;
}
