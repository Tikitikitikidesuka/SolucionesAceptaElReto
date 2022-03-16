#include <iostream>
#include <vector>


using std::vector;

typedef std::int_fast16_t c_int;
typedef vector<vector<vector<c_int>>> Matrix3;

const c_int NOT_SET = INT32_MIN;


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


c_int maxPuntuacion(c_int duracion, const vector<Cancion>& canciones);
c_int maxPuntuacion(c_int it, c_int c1, c_int c2, const vector<Cancion>& canciones, Matrix3& mat);

c_int maxPuntuacion(c_int duracion, const vector<Cancion>& canciones) {
    c_int numCanciones = canciones.size();

    // mat[cancion][capacidad1][capacidad2];
    Matrix3 mat(numCanciones + 1, vector<vector<c_int>>(duracion + 1, vector<c_int>(duracion + 1, NOT_SET)));

    return maxPuntuacion(numCanciones, duracion, duracion, canciones, mat);
}

c_int maxPuntuacion(c_int it, c_int c1, c_int c2, const vector<Cancion>& canciones, Matrix3& mat) {
    // Caso base
    if(it == 0)
        return 0;

    // Caso recursivo
    c_int tempMaxPuntuacion = 0;
    if(c1 - canciones[it-1].duracion >= 0) {
        if(mat[it-1][c1 - canciones[it-1].duracion][c2] != NOT_SET)
            tempMaxPuntuacion = mat[it-1][c1 - canciones[it-1].duracion][c2] + canciones[it-1].puntuacion;
        else
            tempMaxPuntuacion = maxPuntuacion(it-1, c1 - canciones[it-1].duracion, c2, canciones, mat) + canciones[it-1].puntuacion;
    }
    if(c2 - canciones[it-1].duracion >= 0) {
        if(mat[it-1][c1][c2 - canciones[it-1].duracion] != NOT_SET)
            tempMaxPuntuacion = std::max(tempMaxPuntuacion, mat[it-1][c1][c2 - canciones[it-1].duracion] + canciones[it-1].puntuacion);
        else
            tempMaxPuntuacion = std::max(tempMaxPuntuacion, maxPuntuacion(it-1, c1, c2 - canciones[it-1].duracion, canciones, mat) + canciones[it-1].puntuacion);
    }
    if(mat[it-1][c1][c2] != NOT_SET)
        tempMaxPuntuacion = std::max(tempMaxPuntuacion, mat[it-1][c1][c2]);
    else
        tempMaxPuntuacion = std::max(tempMaxPuntuacion, maxPuntuacion(it-1, c1, c2, canciones, mat));

    mat[it][c1][c2] = tempMaxPuntuacion;

    return tempMaxPuntuacion;
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