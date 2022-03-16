#include <iostream>
#include <vector>


#define MAX_CANCIONES 30
#define MAX_DURACION 1000
#define MAX_PUNTUACION 10000


using std::vector;

typedef std::int_fast16_t c_int;
typedef vector<vector<vector<c_int>>> Matrix3;


inline void fastIntInput(c_int& number) {
    register std::int_fast8_t input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
}

inline void fastIntOutput(c_int x){
    std::int_fast8_t buffer[35];
    register std::int_fast8_t i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
        putchar_unlocked('\n');
}


class Cancion {
    public:
        c_int duracion;
        c_int puntuacion;
};


c_int maxPuntuacion(c_int duracion, const vector<Cancion>& canciones) {
    const c_int numCanciones = canciones.size();
    Matrix3 mat(2, vector<vector<c_int>>(duracion + 1, vector<c_int>(duracion + 1, 0)));

    // Rellenar
    for(c_int it = 1; it <= numCanciones; ++it) {
        for(c_int c1 = 0; c1 <= duracion; ++c1) {
            for(c_int c2 = 0; c2 <= duracion; ++c2) {
                c_int max = mat[(it-1)%2][c1][c2];

                if(c1 - canciones[it-1].duracion >= 0)
                    max = std::max(max, mat[(it-1)%2][c1 - canciones[it-1].duracion][c2] + canciones[it-1].puntuacion);
                if(c2 - canciones[it-1].duracion >= 0)
                    max = std::max(max, mat[(it-1)%2][c1][c2 - canciones[it-1].duracion] + canciones[it-1].puntuacion);
            
                mat[it%2][c1][c2] = max;
            }
        }
    }

    return mat[numCanciones%2][duracion][duracion];
}


int main() {
    // Program
    c_int numCanciones;
    fastIntInput(numCanciones);
    while(numCanciones != 0) {
        c_int duracion;
        fastIntInput(duracion);

        vector<Cancion> canciones;
        canciones.reserve(numCanciones);

        for(c_int cancionIt = 0; cancionIt < numCanciones; ++cancionIt) {
            Cancion cancion;
            fastIntInput(cancion.duracion);
            fastIntInput(cancion.puntuacion);
            canciones.push_back(cancion);
        }

        fastIntOutput(maxPuntuacion(duracion, canciones));

        fastIntInput(numCanciones);
    }

    return 0;
}