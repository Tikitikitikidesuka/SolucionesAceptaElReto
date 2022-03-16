#include <iostream>
#include <vector>


#define MAX_INPUT 1000


using std::vector;

typedef std::int_fast64_t c_int;
const c_int C_INT_MAX = INT64_MAX;


inline void fastIntInput(c_int& number) {
    register std::int_fast8_t input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - '0';
}

inline bool fastIntInputCheckEnd(c_int& number) {
    register std::int_fast8_t input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked())
        if(input == EOF) return false;
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - '0';
    
    return true;
}


c_int numFormas(c_int longitud, const vector<c_int>& longitudCuerdas) {
    c_int mat[2][MAX_INPUT + 1];

    for(int it = 1; it <= longitud; ++it)
        mat[0][it] = 0;
    
    for(int it = 0; it <= longitudCuerdas.size(); ++it)
        mat[it%2][0] = 1;
    
    for(int it = 1; it <= longitudCuerdas.size(); ++it) {
        for(int l = 1; l <= longitud; ++l) {
            mat[it%2][l] = mat[(it-1)%2][l];
            if(l - longitudCuerdas[it-1] >= 0)
                mat[it%2][l] += mat[(it-1)%2][l - longitudCuerdas[it-1]];
        }
    }

    return mat[longitudCuerdas.size()%2][longitud];
}

c_int minCuerdas(c_int longitud, const vector<c_int>& longitudCuerdas) {
        c_int mat[2][MAX_INPUT + 1];

        for(c_int it = 1; it <= longitud; ++it)
            mat[0][it] = C_INT_MAX;

        for(c_int it = 0; it <= longitudCuerdas.size(); ++it)
            mat[it%2][0] = 0;

        for(c_int it = 1; it <= longitudCuerdas.size(); ++it) {
            for(c_int l = 1; l <= longitud; ++l) {
                if(l - longitudCuerdas[it-1] >= 0 && mat[(it-1)%2][l - longitudCuerdas[it-1]] < C_INT_MAX) {
                    mat[it%2][l] = std::min(mat[(it-1)%2][l], 1 + mat[(it-1)%2][l - longitudCuerdas[it-1]]);
                } else {
                    mat[it%2][l] = mat[(it-1)%2][l];
                }
            }
        }

        return mat[longitudCuerdas.size()%2][longitud];
    }

c_int costeMinimo(c_int longitud, const vector<c_int>& longitudCuerdas, const vector<c_int>& costeCuerdas) {
        c_int mat[2][MAX_INPUT + 1];

        for(c_int it = 1; it <= longitud; ++it)
            mat[0][it] = C_INT_MAX;

        for(c_int it = 0; it <= longitudCuerdas.size(); ++it)
            mat[it%2][0] = 0;

        for(c_int it = 1; it <= longitudCuerdas.size(); ++it) {
            for(c_int l = 1; l <= longitud; ++l) {
                if(l - longitudCuerdas[it-1] >= 0 && mat[(it-1)%2][l - longitudCuerdas[it-1]] < C_INT_MAX) {
                    mat[it%2][l] = std::min(mat[(it-1)%2][l], costeCuerdas[it-1] + mat[(it-1)%2][l - longitudCuerdas[it-1]]);
                } else {
                    mat[it%2][l] = mat[(it-1)%2][l];
                }
            }
        }

        return mat[longitudCuerdas.size()%2][longitud];
    }


int main() {
    c_int cuerdas, objetivo;
    while(fastIntInputCheckEnd(cuerdas)) {
        fastIntInput(objetivo);
        vector<c_int> longCuerdas;
        vector<c_int> costCuerdas;
        longCuerdas.reserve(cuerdas);
        costCuerdas.reserve(cuerdas);

        while(cuerdas--) {
            c_int inputLong, inputCost;
            fastIntInput(inputLong);
            fastIntInput(inputCost);
            longCuerdas.push_back(inputLong);
            costCuerdas.push_back(inputCost);
        }

        c_int formas = numFormas(objetivo, longCuerdas);
        if(formas > 0) {
            std::cout << "SI " << formas << " " <<
                minCuerdas(objetivo, longCuerdas) << " " <<
                costeMinimo(objetivo, longCuerdas, costCuerdas);
        } else {
            std::cout << "NO";
        }
        std::cout << "\n";
    }

    return 0;
}