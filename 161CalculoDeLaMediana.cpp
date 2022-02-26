#include <algorithm>
#include <iostream>
#include <vector>


using std::sort;
using std::vector;
typedef std::int_fast32_t c_int;



int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    c_int numElementos;
    std::cin >> numElementos;
    while(numElementos != 0) {
        vector<c_int> elementos;
        elementos.reserve(numElementos);

        for(c_int elemIt = 0; elemIt < numElementos; ++elemIt) {
            c_int input;
            std::cin >> input;
            elementos.push_back(input);
        }

        sort(elementos.begin(), elementos.end());

        c_int mediana2;
        if(numElementos % 2) {  // Si impar
            mediana2 = elementos[numElementos / 2] * 2;
        } else {                // Si par
            mediana2 = elementos[numElementos / 2] + elementos[numElementos / 2 - 1];
        }

        std::cout << mediana2 << "\n";

        std::cin >> numElementos;
    }

    return 0;
}