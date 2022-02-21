#include <cstring>
#include <iostream>


typedef std::int_fast16_t c_int;


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


constexpr const c_int MAX_SIZE = 1024;


int main() {
    bool check[MAX_SIZE * MAX_SIZE];
    c_int matriz[MAX_SIZE][MAX_SIZE];
    

    c_int size;
    fastIntInput(size);
    while(size != 0) {
        bool diabolico = true; // Se asume que es diabolico
        bool esoterico = true; // Se asume que es esoterico

        c_int sizeSqr = size * size;

        // Set check todo a falso
        memset(check, false, sizeSqr); // memset de cstring

        // Input del cuadrado
        for(c_int y = 0; y < size; ++y) {
            for(c_int x = 0; x < size; ++x) {
                // Input
                c_int input;
                fastIntInput(input);

                // Comprobar si esta dentro del rango valido y sin usar
                if(esoterico) {
                    if(input > sizeSqr) {
                        esoterico = false;
                    } else {
                        esoterico = !check[input-1];
                        check[input-1] = true; // Marcar como usado
                    }
                }

                // Asignar valor a la matriz
                matriz[y][x] = input;
            }
        }
        
        // A estas alturas se ha determinado si rompe la propiedad 1 del esoterico


        // Obtener cm
        c_int cm = 0;
        for(c_int x = 0; x < size; ++x)
            cm += matriz[0][x];

        // Comprobar que todas las filas suman cm
        // (No se comprueba la primera ya que esa establece cm)
        for(c_int y = 1; diabolico && y < size; ++y) {
            c_int test_cm = 0;
            for(c_int x = 0; diabolico && x < size; ++x) {
                test_cm += matriz[y][x];
            }
            diabolico = test_cm == cm;
        }


        // Comprobar que todas las columnas suman cm
        for(c_int x = 0; diabolico && x < size; ++x) {
            c_int test_cm = 0;
            for(c_int y = 0; diabolico && y < size; ++y) {
                test_cm += matriz[y][x];
            }
            diabolico = test_cm == cm;
        }


        // Comprobar que todas las diagonales principales suman cm
        c_int test_cm_diag1 = 0;
        c_int test_cm_diag2 = 0;
        for(c_int i = 0; diabolico && i < size; ++i) {
            test_cm_diag1 += matriz[i][i];
            test_cm_diag2 += matriz[i][size-i-1];
        }
        diabolico = test_cm_diag1 == cm && test_cm_diag2 == cm;


        // Propiedad 0 del esoterico (debe ser diabolico)
        if(!diabolico)
            esoterico = false;

        // A estas alturas ya se ha determinado completamente si es diabolico

        
        // Comprobar si se rompe la propiedad 2 del esoterico (suma de esquinas)
        c_int cm2;
        if(esoterico) {
            cm2 = (4 * cm) / size;
            c_int test_cm2 = matriz[0][0] + matriz[0][size-1] + 
                            matriz[size-1][0] + matriz[size-1][size-1];
            esoterico = cm2 == test_cm2;
        }

        // A estas alturas se ha determinado si rompe la propiedad 2 del esoterico


        c_int centro = 0;
        // Comprobar si se cumple la propiedad 3 o 4 del esoterico
        if(esoterico) {
            centro = size / 2;
            if(size % 2 != 0) {  // Si el lado es impar 
                // Comprobar 3.1
                c_int sum_clat = matriz[0][centro] + matriz[centro][0] +                // Arriba + Izquierda
                                matriz[size-1][centro] + matriz[centro][size-1];        // Abajo  + Derecha
                esoterico = sum_clat == cm2;

                // Si sigue siendo esoterico comprobar 3.2
                if(esoterico) {
                    esoterico = matriz[centro][centro] * 4 == cm2;
                }
                
            } else {        // Si el lado es par
                // Comprobar 4.1
                c_int sum_clat = matriz[0][centro-1] + matriz[0][centro] +              // Arriba
                                 matriz[centro-1][0] + matriz[centro][0] +              // Izquierda
                                 matriz[size-1][centro-1] + matriz[size-1][centro] +    // Abajo
                                 matriz[centro-1][size-1] + matriz[centro][size-1];     // Derecha
                esoterico = sum_clat == cm2 * 2;

                // Si sigue siendo esoterico comprobar 4.2
                if(esoterico) {
                    c_int sum_cent = matriz[centro-1][centro-1] + matriz[centro-1][centro] +
                                    matriz[centro][centro-1] + matriz[centro][centro];
                    esoterico = sum_cent == cm2;
                }
            }
        }

        // A estas alturas se ha determinado si rompe la propiedad 3 o 4 del esoterico
        

        // Imprimir resultados
        if(esoterico) {
            putchar_unlocked('E');
            putchar_unlocked('S');
            putchar_unlocked('O');
            putchar_unlocked('T');
            putchar_unlocked('E');
            putchar_unlocked('R');
            putchar_unlocked('I');
            putchar_unlocked('C');
            putchar_unlocked('O');
        } else if(diabolico) {
            putchar_unlocked('D');
            putchar_unlocked('I');
            putchar_unlocked('A');
            putchar_unlocked('B');
            putchar_unlocked('O');
            putchar_unlocked('L');
            putchar_unlocked('I');
            putchar_unlocked('C');
            putchar_unlocked('O');
        }
        else {
            putchar_unlocked('N');
            putchar_unlocked('O');
        }
        putchar_unlocked('\n');


        // Volver a tomar input de size
        fastIntInput(size);
    }

    return 0;
}