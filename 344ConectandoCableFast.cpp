#include <iostream>


typedef std::int_fast8_t c_char;
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


int main() {
    c_int casos;
    fastIntInput(casos);
    while(casos--) {
        c_int conexiones;
        c_int h = 0, m = 0;
        fastIntInput(conexiones);
        conexiones *= 2;

        c_char input = getchar_unlocked();
        while(input < 'A') input = getchar_unlocked();

        while(conexiones--) {
            while(input < 'A')
                input = getchar_unlocked();

            if(input == 'H')
                ++h;
            else
                ++m;
            input = getchar_unlocked();
        }

        std::cout << (h == m ? "POSIBLE" : "IMPOSIBLE") << "\n";
    }

    return 0;
}