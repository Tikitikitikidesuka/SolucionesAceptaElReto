#include <algorithm>
#include <iostream>
#include <vector>


using std::vector;
typedef std::int_fast32_t c_int;


inline bool fastIntInput(int& number) {
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

inline void fastOutput(int x){
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
    int numAscensores;
    while(fastIntInput(numAscensores)) {
        int ultimaPlanta = 0;
        std::vector<Ascensor> ascensores;
        ascensores.reserve(numAscensores);

        // Input de ascensores
        while(numAscensores > 0) {
            int from, to, lvl;
            fastIntInput(from);
            fastIntInput(to);
            fastIntInput(lvl);
            if(to > ultimaPlanta) ultimaPlanta = to;
            Ascensor ascensor = Ascensor(from, to, lvl);
            ascensores.push_back(ascensor);

            --numAscensores;
        }

        Edificio edificio(ultimaPlanta + 1);

        // Ordenar ascensores de menor a mayor nivel
        std::sort(ascensores.begin(), ascensores.end());
        
        std::vector<Ascensor>::iterator ascensorIter = ascensores.begin();
        edificio.addAscensor(*ascensorIter);
        while(ascensorIter++ != ascensores.end() && !edificio.ultimoPisoAlcanzable()) {
            edificio.addAscensor(*ascensorIter);
        }

        fastOutput((ascensorIter-1)->lvl);
    }


    return 0;
}