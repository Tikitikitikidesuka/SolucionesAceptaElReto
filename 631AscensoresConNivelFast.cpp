#include <algorithm>
#include <iostream>
#include <vector>


#define MAX_ASCENSORES 100000
#define MAX_PISOS 1000000


using std::vector;
typedef std::int_fast32_t c_int;


inline bool fastIntInput(c_int& number) {
    register std::int_fast8_t  input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked())
        if(input == EOF) return false;
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
    
    return true;
}

inline void fastOutput(c_int x){
    char buffer[35];
    register int i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
        putchar_unlocked('\n');
}


class Ascensor {
    public:
        c_int lvl;
        c_int minPiso;
        c_int maxPiso;

        Ascensor() {}

        Ascensor(c_int minPiso, c_int maxPiso, c_int lvl):
            minPiso(minPiso), maxPiso(maxPiso), lvl(lvl)
        {}

        bool operator<(const Ascensor& ascensor) const {
            return lvl < ascensor.lvl;
        }
};


class Edificio {
    private:
        enum EstadoPiso { NADA = 0, ARRIBA = 1, ABAJO = 2, AMBOS = 3 };

        c_int alcanzableVal;
        vector<EstadoPiso> pisos;

        void updatePiso(c_int piso, EstadoPiso newEstado) {
            if(pisos[piso] == NADA) {
                alcanzableVal -= newEstado - pisos[piso];
                pisos[piso] = newEstado;
            } else if(pisos[piso] != AMBOS) {
                if(newEstado != pisos[piso]) {
                    alcanzableVal -= AMBOS - pisos[piso];
                    pisos[piso] = AMBOS;
                }
            }
        }

    public:
        Edificio(c_int pisos): 
            alcanzableVal(3 * (pisos - 1)),
            pisos(vector<EstadoPiso>(pisos, NADA))
        {}

        void addAscensor(const Ascensor& ascensor) {
            if(ascensor.minPiso < ascensor.maxPiso) {
                updatePiso(ascensor.minPiso, ABAJO);
                for(c_int piso = ascensor.minPiso + 1; piso < ascensor.maxPiso; ++piso)
                    updatePiso(piso, AMBOS);
                updatePiso(ascensor.maxPiso, ARRIBA);
            }
        }

        bool ultimoPisoAlcanzable() {
            return alcanzableVal == 0;
        }
};


int main() {
    c_int numAscensores;
    Ascensor ascensores[MAX_ASCENSORES];
    while(fastIntInput(numAscensores)) {
        c_int ultimaPlanta = 0;
        c_int ascensorIndex = 0;

        // Input de ascensores
        while(ascensorIndex < numAscensores) {
            fastIntInput(ascensores[ascensorIndex].minPiso);
            fastIntInput(ascensores[ascensorIndex].maxPiso);
            fastIntInput(ascensores[ascensorIndex].lvl);
            if(ascensores[ascensorIndex].maxPiso > ultimaPlanta)
                ultimaPlanta = ascensores[ascensorIndex].maxPiso;
            
            ++ascensorIndex;
        }

        Edificio edificio(ultimaPlanta + 1);

        // Ordenar ascensores de menor a mayor nivel
        std::sort(ascensores, ascensores + numAscensores);
        
        c_int ascensorIt = 0;
        edificio.addAscensor(ascensores[ascensorIt]);
        for(++ascensorIt; ascensorIt < numAscensores && !edificio.ultimoPisoAlcanzable(); ++ascensorIt) {
            edificio.addAscensor(ascensores[ascensorIt]);
        }

        fastOutput(ascensores[ascensorIt -1].lvl);
    }


    return 0;
}