#include <iostream>
#include <vector>


typedef std::int_fast32_t c_int;


int main() {
    // Easy fast I/O for cin and cout
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    c_int numCasas;
    while(std::cin >> numCasas && numCasas != 0) {
        std::vector<c_int> casas;
        casas.reserve(numCasas);

        for(c_int cntr = 0; cntr < numCasas; cntr++) {
            c_int input;
            std::cin >> input;
            casas.push_back(input);
        }

        c_int propag = 0, suma = 0;
        std::vector<c_int>::reverse_iterator it = casas.rbegin();
        while(it != casas.rend()) {
            // Actualizar propagacion
            propag--;

            // Contar si escucha
            if(propag > 0)
                suma++;

            // Generar propagacion
            if(*it >= propag)
                propag = *it + 1;

            ++it;
        }

        std::cout << suma << "\n";
    }
}