#include <iostream>

#define SOL     0
#define ARBOL   1
#define SOMBRA  2


int matriz[50][50];


inline void fastInput(int* number) {
    register int input;
 
    *number = 0;
    input = getchar_unlocked();
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        *number = *number * 10 + input - 48;
}


inline void fastOutput(int x){
    register char buffer[35];
    register int i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
        putchar_unlocked('\n');
}


int ponerArbol(int posX, int posY, int sizeX, int sizeY);

void resetMatriz(int sizeX, int sizeY);


int main() {
    int sizeX, sizeY, arboles;
    fastInput(&sizeX);
    fastInput(&sizeY);
    fastInput(&arboles);
    while(sizeX != 0) {
        int sombras = 0;
        resetMatriz(sizeX, sizeY);
        
        while(arboles > 0) {
            int posX, posY;
            fastInput(&posX);
            fastInput(&posY);

            sombras += ponerArbol(posX, posY, sizeX, sizeY);

            arboles--;
        }

        fastOutput(sombras);

        fastInput(&sizeX);
        fastInput(&sizeY);
        fastInput(&arboles);
    }
    return 0;
}


int ponerArbol(int posX, int posY, int sizeX, int sizeY) {
    int sombras = 0;

    if(matriz[posX-1][posY-1] == SOMBRA)
        sombras--;

    matriz[posX-1][posY-1] = ARBOL;

    for(int y = posY-2; y <= posY; y++) {
        if(y >= 0 && y < sizeY) {
            for(int x = posX-2; x <= posX; x++) {
                if(x >= 0 && x < sizeX && matriz[x][y] == SOL) {
                    matriz[x][y] = SOMBRA;
                    sombras++;
                }
            }
        }
    }

    return sombras;
}

void resetMatriz(int sizeX, int sizeY) {
    for(int y = 0; y < sizeY; y++) {
        for(int x = 0; x < sizeX; x++) {
            matriz[x][y] = SOL;
        }
    }
}
