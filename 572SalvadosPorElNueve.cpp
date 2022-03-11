#include <iostream>


typedef float c_float;
typedef std::int_fast8_t c_bool;
typedef std::int_fast16_t c_int;


int main() {
    // Fast I/O
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    c_int casos;
    std::cin >> casos;
    while(casos--) {
        c_bool cero = false, overNueve = false;
        for(c_int it = 0; it < 5; ++it) {
            c_float nota;
            std::cin >> nota;
            if(nota >= 9) {
                overNueve = true;
            } else if(nota == 0) {
                cero = true;
            }
        }

        if(overNueve) {
            std::cout << "MEDIA";
        } else if(cero) {
            std::cout << "SUSPENSO DIRECTO";
        } else {
            std::cout << "MEDIA";
        }
        std::cout << "\n";
    }

    return 0;
}