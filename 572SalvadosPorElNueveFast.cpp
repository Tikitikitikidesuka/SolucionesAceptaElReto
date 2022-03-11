#include <iostream>


typedef std::int_fast8_t c_bool;
typedef std::int_fast16_t c_int;


inline void getNum1Decimal_t10(c_int& num) {
    // Clear buffer noise
    c_int input = getchar_unlocked();
    for(; input < '0' || input > '9'; input = getchar_unlocked());

    // Digito mas significativo
    num = (input - '0');
    // Check punto
    input = getchar_unlocked();
    if(input != '.') {
        num = num * 10 + input - '0';
        input = getchar_unlocked();
    }
    num = num * 10 + getchar_unlocked() - '0';
}


int main() {
    c_int casos;
    std::cin >> casos;
    while(casos--) {
        c_bool cero = false, overNueve = false;
        for(c_int it = 0; it < 5; ++it) {
            c_int nota_t10;
            getNum1Decimal_t10(nota_t10);
            if(nota_t10 >= 90) {
                overNueve = true;
            } else if(nota_t10 == 0) {
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