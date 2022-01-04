#include <iostream>
#include <vector>

int main() {
    int numCasas;
    while(std::cin >> numCasas && numCasas != 0) {
        std::vector<int> casas;

        for(int cntr = 0; cntr < numCasas; cntr++) {
            int input;
            std::cin >> input;
            casas.push_back(input);
        }

        int propag = 0, suma = 0;
        std::vector<int>::iterator it = casas.end();
        while(it != casas.begin()) {
            // Actualizar iterador
            it--;

            // Actualizar propagacion
            propag--;

            // Contar si escucha
            if(propag > 0)
                suma++;

            // Generar propagacion
            if(*it >= propag)
                propag = *it +1;
        }

        std::cout << suma << "\n";
    }
}