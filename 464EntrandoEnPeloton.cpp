#include <iostream>
#include <vector>
#include <algorithm>


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

inline void fastTimeInput(c_int& time) {
    time = 0;
    c_int input;

    fastIntInput(input);
    time += input * 3600;
    fastIntInput(input);
    time += input * 60;
    fastIntInput(input);
    time += input;
}


class Intervalo {
    public:
        c_int from;
        c_int to;
        c_int prevN;

        Intervalo()
        {}

        Intervalo(c_int pos): 
            from(pos), to(pos) 
        {}

        Intervalo(c_int from, c_int to):
            from(from), to(to)
        {}

        c_int size() const {
            return to - from + 1;
        }

        bool contiene(c_int time) const {
            return time >= from && time <= to;
        }
};


c_int getIntervalo(c_int time, const vector<Intervalo>& intervalos) {
    c_int from = 0, to = intervalos.size() - 1;
    c_int pivote = (from + to) / 2;
    
    while(from <= to && !intervalos[pivote].contiene(time)) {
        if(time < intervalos[pivote].to)
            to = pivote - 1;
        else
            from = pivote + 1;
        pivote = (from + to) / 2;
    }

    return pivote;
}


int main() {
    c_int casos;
    while(fastIntInput(casos)) {
        // Input de tiempos
        vector<c_int> tiempos;
        tiempos.reserve(casos);
        for(c_int caso = 0; caso < casos; ++caso) {
            c_int timeIn;
            fastTimeInput(timeIn);
            tiempos.push_back(timeIn);
        }

        // Obtener tiempos ordenados
        vector<c_int> ordenados(tiempos);
        std::sort(ordenados.begin(), ordenados.end(), std::less<c_int>());

        // Generar intervalos
        vector<Intervalo> intervalos;
        //intervalos.reserve(casos);

        c_int pos = 0, prevN = 0;
        while(pos < ordenados.size()) {
            c_int currentPrevN = 1;
            Intervalo intervalo(ordenados[pos]);
            pos++;

            while(pos < ordenados.size() && ordenados[pos] - intervalo.to <= 1) {
                intervalo.to = ordenados[pos];
                ++currentPrevN;
                ++pos;
            }

            intervalo.prevN = prevN;
            intervalos.push_back(intervalo);
            prevN += currentPrevN;
        }

        // Obtener e imprimir posicion
        for(c_int it = 0; it < tiempos.size(); ++it) {
            c_int intervaloIndex = getIntervalo(tiempos[it], intervalos);
            std::cout << intervalos[intervaloIndex].prevN + 1 << "\n";
        }
        std::cout << "---\n";
    }

    return 0;
}