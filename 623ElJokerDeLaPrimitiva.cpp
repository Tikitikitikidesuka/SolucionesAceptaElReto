#include <iostream>
#include <vector>


int main() {
    std::vector<int> digitosBoleto(10, 0);
    std::vector<int> digitosPremiado(10, 0);

    int casos;
    std::cin >> casos;
    for(int cntr = 0; cntr < casos; cntr++) {
        int input;
        std::cin >> input;
        for(int digitoCntr = 0; digitoCntr < 7; digitoCntr++) {
            int digito = input % 10;
            input /= 10;
            digitosPremiado[digito]++;
        }
        std::cin >> input;
        for(int digitoCntr = 0; digitoCntr < 7; digitoCntr++) {
            int digito = input % 10;
            input /= 10;
            digitosBoleto[digito]++;
        }

        bool valido = true;
        for(int digitoCntr = 0; digitoCntr < 10 && valido; digitoCntr++) {
            if(digitosBoleto[digitoCntr] != digitosPremiado[digitoCntr])
                valido = false;
        }

        if(valido)
            std::cout << "GANA\n";
        else
            std::cout << "PIERDE\n";
        

        std::fill(digitosBoleto.begin(), digitosBoleto.end(), 0);
        std::fill(digitosPremiado.begin(), digitosPremiado.end(), 0);
    }
    return 0;
}