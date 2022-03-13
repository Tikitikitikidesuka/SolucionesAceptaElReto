#include <iostream>
#include <vector>


using std::vector;

typedef std::int_fast32_t c_int;
typedef vector<vector<vector<c_int>>> Matrix3;

const c_int NOT_SET = INT32_MIN;


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
    //Fast input
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    // Program
    c_int numCanciones;
    std::cin >> numCanciones;
    while(numCanciones != 0) {
        c_int duracion;
        std::cin >> duracion;

        vector<Cancion> canciones;
        canciones.reserve(numCanciones);

        for(c_int cancionIt = 0; cancionIt < numCanciones; ++cancionIt) {
            Cancion cancion;
            std::cin >> cancion.duracion >> cancion.puntuacion;
            canciones.push_back(cancion);
        }

        std::cout << maxPuntuacion(duracion, canciones) << "\n";

        std::cin >> numCanciones;
    }

    return 0;
}



// BACKTRACKING ES DEMASIADO LENTO :( //

/*
c_int maxPuntuacionBacktracking(c_int duracion, const vector<Cancion>& canciones);
void maxPuntuacionBacktracking(c_int it, c_int duracion, c_int acumulado, c_int maxSumaRestante, c_int c1, c_int c2, c_int& currentMax, const vector<Cancion>& canciones);


c_int maxPuntuacionBacktracking(c_int duracion, const vector<Cancion>& canciones) {
    c_int currentMax = 0;

    c_int maxSumaRestante = 0;
    for(Cancion cancion : canciones) 
        maxSumaRestante += cancion.puntuacion;

    maxPuntuacionBacktracking(0, duracion, 0, maxSumaRestante, 0, 0, currentMax, canciones);

    return currentMax;
}

void maxPuntuacionBacktracking(c_int it, c_int duracion, c_int acumulado, c_int maxSumaRestante, c_int c1, c_int c2, c_int& currentMax, const vector<Cancion>& canciones) {
    if(acumulado > currentMax)
        currentMax = acumulado;

    // Casos base
    if(acumulado + maxSumaRestante <= currentMax)
        return;

    if(it == canciones.size())
        return;

    
    // Caso recursivo
    if(c1 + canciones[it].duracion <= duracion)
        maxPuntuacionBacktracking(it+1, duracion, acumulado+canciones[it].puntuacion, maxSumaRestante-canciones[it].puntuacion, c1 + canciones[it].duracion, c2, currentMax, canciones);
    if((c1 != 0 || c2 != 0) && c2 + canciones[it].duracion <= duracion)
        maxPuntuacionBacktracking(it+1, duracion, acumulado+canciones[it].puntuacion, maxSumaRestante-canciones[it].puntuacion, c1, c2 + canciones[it].duracion, currentMax, canciones);
    maxPuntuacionBacktracking(it+1, duracion, acumulado, maxSumaRestante-canciones[it].puntuacion, c1, c2, currentMax, canciones);
}


int main() {
    //Fast input
    //std::cin.tie(NULL);
    //std::ios_base::sync_with_stdio(false);

    // Program
    c_int numCanciones;
    std::cin >> numCanciones;
    while(numCanciones != 0) {
        c_int duracion;
        std::cin >> duracion;

        vector<Cancion> canciones;
        canciones.reserve(numCanciones);

        for(c_int cancionIt = 0; cancionIt < numCanciones; ++cancionIt) {
            Cancion cancion;
            std::cin >> cancion.duracion >> cancion.puntuacion;
            canciones.push_back(cancion);
        }

        std::cout << maxPuntuacionBacktracking(duracion, canciones) << "\n";

        std::cin >> numCanciones;
    }

    return 0;
}
*/



// NO VALE HACER EL PROBLEMA DE LA MOCHILA DOS VECES :( //

/*
void maxPuntuacionFillMat(c_int mat[MAX_CANCIONES + 1][MAX_DURACION + 1], c_int duracion, const vector<c_int>& duracionesC, const vector<c_int>& puntuacionesC) {
    // duracion(0) = 0
    for(c_int it = 0; it <= duracionesC.size(); ++it)
        mat[it][0] = 0;
    
    // itCancion(0) = 0
    for(c_int it = 1; it <= duracion; ++it)
        mat[0][it] = 0;

    // rellenar matriz
    for(c_int it = 1; it <= duracionesC.size(); ++it) {
        for(c_int d = 1; d <= duracion; ++d) {
            if(d - duracionesC[it-1] < 0) {
                mat[it][d] = mat[it-1][d];
            } else {
                mat[it][d] = std::max(
                    mat[it-1][d - duracionesC[it-1]] + puntuacionesC[it-1],
                    mat[it-1][d]
                );
            }
        }
    }
}

c_int maxPuntuacion(c_int duracion, const vector<c_int>& duracionesC, const vector<c_int>& puntuacionesC) {
    c_int mat[MAX_CANCIONES + 1][MAX_DURACION + 1];

    maxPuntuacionFillMat(mat, duracion, duracionesC, puntuacionesC);
    
    return mat[duracionesC.size()][duracion];
}

c_int maxPuntuacion(c_int duracion, const vector<c_int>& duracionesC, const vector<c_int>& puntuacionesC, vector<c_int>& newDuracionesC, vector<c_int>& newPuntuacionesC) {
    c_int mat[MAX_CANCIONES + 1][MAX_DURACION + 1];

    maxPuntuacionFillMat(mat, duracion, duracionesC, puntuacionesC);

    // Actualizar vectores
    c_int posIt = duracionesC.size();
    c_int posD = duracion;

    while(posIt > 0) {
        if(posD <= 0 || mat[posIt][posD] == mat[posIt-1][posD]) { // Si no se ha usado
            newDuracionesC.push_back(duracionesC[posIt-1]);
            newPuntuacionesC.push_back(puntuacionesC[posIt-1]);
        } else {
            posD -= duracionesC[posIt-1];
        }
        --posIt;
    }
    
    return mat[duracionesC.size()][duracion];
}


int main() {
    c_int canciones;
    std::cin >> canciones;
    while(canciones != 0) {
        c_int duracion;
        std::cin >> duracion;

        vector<c_int> cara1Duraciones;
        vector<c_int> cara1Puntuaciones;
        cara1Duraciones.reserve(canciones);
        cara1Puntuaciones.reserve(canciones);

        for(c_int cancion = 0; cancion < canciones; ++cancion) {
            c_int inputDuracion, inputPuntuacion;
            std::cin >> inputDuracion >> inputPuntuacion;
            cara1Duraciones.push_back(inputDuracion);
            cara1Puntuaciones.push_back(inputPuntuacion);
        }

        vector<c_int> cara2Duraciones;
        vector<c_int> cara2Puntuaciones;
        cara2Duraciones.reserve(canciones);
        cara2Puntuaciones.reserve(canciones);

        c_int maxPuntuacionResult = maxPuntuacion(duracion, cara1Duraciones, cara1Puntuaciones, cara2Duraciones, cara2Puntuaciones);
        if(cara2Duraciones.size() > 0)
            maxPuntuacionResult += maxPuntuacion(duracion, cara2Duraciones, cara2Puntuaciones);

        std::cout << maxPuntuacionResult << "\n";

        std::cin >> canciones;
    }

    return 0;
}
*/