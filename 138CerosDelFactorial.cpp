#include <iostream>


typedef std::int_fast64_t c_int;


/** 
 *  Se quiere saber cuantas veces se multiplica por 10.
 *  Se puede descomponer a 5 * 2.
 *  El numero de ceros seria el minimo de multiplicaciones por 2
 *  y multiplicaciones por 5.
 *  Siempre va a haber mas multipliaciones por 2 que por 5, por lo que
 *  vale con contar el numero de veces que se multiplica por 5.
 */

c_int cerosFactorialSlow(c_int num) {
    c_int cincos = 0;

    for(c_int res = 2; res <= num; ++res) {
        c_int test = res;
        while(test % 5 == 0) {
            test /= 5;
            ++cincos;
        }
    }

    return cincos;
}

/** 
 *  El metodo anterior es lento. Existe una mejor forma de contar
 *  el numero de multiplicaciones por 5:
 *  - - - - 5 - - - - 5 - - - - 5 - - - - - 5 - - - - - 5 - - - - - 5 ...
 *  - - - - - - - - - - - - - - - - - - - - - - - - - - 5 - - - - - - ...
 */

c_int cerosFactorial(c_int num) {
    c_int cincos = 0;

    for(c_int mul5 = 5; num / mul5 > 0; mul5 *= 5)
        cincos += num / mul5;

    return cincos;
}


int main() {
    c_int casos;
    std::cin >> casos;
    while(casos--) {
        c_int input;
        std::cin >> input;
        std::cout << cerosFactorial(input) << "\n";
    }

    return 0;
}