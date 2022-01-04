#include <iostream>


int main() {
    int numCalcetines;
    while(std::cin >> numCalcetines && numCalcetines != 0) {
        bool emparejados[100];
        for(int cntr = 0; cntr < 100; cntr++)
            emparejados[cntr] = true;
        int desemparejados = 0, maxDesemparejados = 0;
        for(int calcetinCntr = 0; calcetinCntr < numCalcetines; calcetinCntr++) {
            int tipo;
            std::cin >> tipo;
            tipo--;
            if(emparejados[tipo]) { // Si esta emparejado
                desemparejados++;
                if(desemparejados > maxDesemparejados)
                    maxDesemparejados = desemparejados;
            } else { // Si no esta emparejado
                desemparejados--;
            }
            emparejados[tipo] = !emparejados[tipo];
        }
        std::cout << maxDesemparejados << "\n";
    }    
    return 0;
}