#include <iostream>


typedef std::int_fast8_t c_char;
typedef std::int_fast16_t c_int;


int main() {
    c_int casos;
    std::cin >> casos;
    while(casos--) {
        c_int conexiones;
        c_int h = 0, m = 0;
        std::cin >> conexiones;
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