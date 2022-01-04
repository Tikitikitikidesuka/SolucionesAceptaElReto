#include <iostream>
#include <vector>


int pow2(int exp) {
    if(exp == 0)
        return 1;
    else
        return 2 << exp-1;
}

int main() {
    int jugadores, rondas;
    while(std::cin >> jugadores >> rondas && (jugadores != 0 || rondas != 0)) {
        std::cin.get();

        std::vector<int> participaciones;
        for(int jugadorCntr = 0; jugadorCntr < jugadores; jugadorCntr++) {
            char input;
            std::cin.get(input);
            participaciones.push_back(input - '0');
        }
        std::cin.get();

        int jugadas = 0;
        for(int rondaCntr = 1; rondaCntr <= rondas; rondaCntr++) {
            int pow2Ronda = pow2(rondaCntr);
            int pow2RondaMin1 = pow2(rondaCntr-1);
            int jugadoresRonda = jugadores / pow2RondaMin1;
            for(int jugador = 0; jugador < jugadoresRonda; jugador += 2) {
                if(participaciones[jugador] && participaciones[jugador+pow2RondaMin1]){
                    jugadas++;
                    participaciones[jugador/pow2Ronda] = 1;
                }
                if(participaciones[jugador] || participaciones[jugador+pow2RondaMin1]){
                    participaciones[jugador/pow2Ronda] = 1;
                }
                else {
                    participaciones[jugador/pow2Ronda] = 0;
                }
            }
        }

        std::cout << jugadas << "\n";
    }
    return 0;
}