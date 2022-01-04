#include <iostream>
#include <climits>
#include <vector>


// Maximo sabor mínimo grosor
int main() {
    long long mejorSabor = 0, mejorGrosor = LLONG_MAX;
    std::vector<int> uvasMejorSabor;
    std::vector<int> uvasMejorGrosor;

    long long sabor, grosor, cntr = 0;
    while(std::cin >> sabor >> grosor) {
        if(sabor == 0 && grosor == 0) {
            bool encontrada = false;
            int saborCntr = 0, grosorCntr = 0;
            while(!encontrada && saborCntr < uvasMejorSabor.size() && grosorCntr < uvasMejorGrosor.size()) {
                //std::cout << "Chikeando: " << uvasMejorSabor[saborCntr] << " vs " << uvasMejorGrosor[grosorCntr] << "\n";
                encontrada = uvasMejorSabor[saborCntr] == uvasMejorGrosor[grosorCntr];
                if(uvasMejorSabor[saborCntr] < uvasMejorGrosor[grosorCntr]) saborCntr++;
                else grosorCntr++;
            }

            if(encontrada)
                std::cout << mejorSabor << " " << mejorGrosor << "\n";
            else
                std::cout << "NO HAY MEJOR\n";
                
            cntr = 0;
            mejorSabor = 0; mejorGrosor = LLONG_MAX;
            uvasMejorSabor.clear();
            uvasMejorGrosor.clear();
        } else {
            //std::cout << "Sabor: " << sabor << " vs " << mejorSabor << " Grosor: " << grosor << " vs " << mejorGrosor << "\n";
            if(sabor > mejorSabor) {
                mejorSabor = sabor;
                uvasMejorSabor.clear();
                uvasMejorSabor.push_back(cntr);
            } else if(sabor == mejorSabor) {
                uvasMejorSabor.push_back(cntr);
            }
            if(grosor < mejorGrosor) {
                mejorGrosor = grosor;
                uvasMejorGrosor.clear();
                uvasMejorGrosor.push_back(cntr);
            } else if(grosor == mejorGrosor) {
                uvasMejorGrosor.push_back(cntr);
            }
            //std::cout << "Mejor sabor: " << uvaMejorSabor << " Mejor grosor: " << uvaMejorGrosor << "\n";
            cntr++;
        }
    }
}