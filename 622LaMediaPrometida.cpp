#include <iostream>


int main() {
    int numNotas;
    while(std::cin >> numNotas && numNotas != 0) {
        int suma = 0, input, objetivo;
        for(int cntr = 0; cntr < numNotas; cntr++) {
            std::cin >> input;
            suma += input;
        }
        std::cin >> objetivo;
        int temp = objetivo * (numNotas + 1);
        int sol = temp - suma;
        if(sol >= 0 && sol <= 10)
            std::cout << sol << "\n";
        else
            std::cout << "IMPOSIBLE\n";
    }    
    return 0;
}