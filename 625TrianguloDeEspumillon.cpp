#include <algorithm>
#include <iostream>
#include <vector>


using std::sort;
using std::vector;
typedef std::int_fast8_t c_bool;
typedef std::int_fast32_t c_int;


/** Se basa en el teorema de la desigualdad triangular:
 *      La suma de dos lados cualesquiera de un triangulo siempre
 *      sera mayor que la longitud del restante.
 * 
 *  Esta funcion asume que los lados se van a introducir en orden decreciente,
 *  por lo que solo comprueba que a < b + c.
 */
inline c_bool ladosFormanTrianguloSorted(c_int a, c_int b, c_int c) {
    return a < b + c;
}


int main() {
    c_int casos;
    std::cin >> casos;

    while(casos--) {
        c_int numLados;
        std::cin >> numLados;

        vector<c_int> lados;
        lados.reserve(3000);
        for(c_int ladoIt = 0; ladoIt < numLados; ++ladoIt) {
            c_int lado;
            std::cin >> lado;
            lados.push_back(lado);
        }

        sort(lados.begin(), lados.end(), std::greater<int>());

        c_bool encontrado = false;
        c_int perimetro, usados = 0;
        while(usados < numLados - 2 && !encontrado) {
            if(ladosFormanTrianguloSorted(lados[usados], lados[usados+1], lados[usados+2])) {
                perimetro = lados[usados] + lados[usados+1] + lados[usados+2];
                encontrado = true;
            }
            ++usados;
        }

        if(encontrado)
            std::cout << perimetro << "\n";
        else
            std::cout << "NO HAY NINGUNO\n";
    }

    return 0;
}