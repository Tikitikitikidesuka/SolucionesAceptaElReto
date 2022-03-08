#include <iostream>
#include <cstring>


#define MAX_PUNTUACION 1000
#define MAX_CARA_OP 7
#define CARAS_DADO 6


typedef std::int_fast8_t c_bool;
typedef std::int_fast16_t c_int;


enum GANA_ESTADO {NS, GANA, PIERDE};
GANA_ESTADO ganaBuffer[MAX_PUNTUACION][CARAS_DADO];


c_bool gana(c_int suma, c_int cara) {
    // Caso base
    if(suma >= 1000)
        return true;
    
    // Caso almacenado
    if(ganaBuffer[suma][cara] != GANA_ESTADO::NS) {
        return ganaBuffer[suma][cara] == GANA_ESTADO::GANA;
    }

    // Caso recursivo
    c_bool ganaRec = false;
    c_int notCara = MAX_CARA_OP - cara;
    for(c_int newCara = 1; !ganaRec && newCara <= CARAS_DADO; ++newCara) {
        if(newCara != notCara && newCara != cara) {
            ganaRec = ganaRec || !gana(suma + newCara, newCara);
        }
    }

    if(ganaRec)
        ganaBuffer[suma][cara] = GANA_ESTADO::GANA;
    else
        ganaBuffer[suma][cara] = GANA_ESTADO::PIERDE;

    return ganaRec;
}


int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::memset(ganaBuffer, GANA_ESTADO::NS, sizeof ganaBuffer); 

    c_int casos;
    std::cin >> casos;
    while(casos--) {
        c_int suma, cara;
        std::cin >> suma >> cara;
        std::cout << ( gana(suma, cara) ? "GANA" : "PIERDE" ) << "\n";
    }

    return 0;
}