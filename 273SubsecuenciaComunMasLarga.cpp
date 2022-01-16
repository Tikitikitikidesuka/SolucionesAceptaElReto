#include <iostream>
#include <string>


int subsecuenciaComunMasLarga(const std::string& secuencia1, const std::string& secuencia2) {
    int matriz[1001][2];

    int length1 = secuencia1.length();
    int length2 = secuencia2.length();

    for(int i = 0; i <= length1; i++)
        matriz[i][0] = 0;
    matriz[0][1] = 0;

    for(int j = 1; j <= length2; j++) {
        for(int i = 1; i <= length1; i++) {
            if(secuencia1[i - 1] == secuencia2[j - 1])
                matriz[i][j % 2] = matriz[i - 1][(j - 1) % 2] + 1;
            else
                matriz[i][j % 2] = std::max(matriz[i - 1][(j - 1) % 2], std::max(matriz[i - 1][j % 2], matriz[i][(j - 1) % 2]));
        }
    }

    return matriz[length1][length2 % 2];
}


inline bool fastStringInput(std::string& inputStr) {
    register char inputChar;
 
    inputStr.clear();
    inputChar = getchar_unlocked();

    // Clear noise on buffer
    for (; (inputChar <= ' '); inputChar = getchar_unlocked())
        if(inputChar == EOF) return false;
 
    // Get number
    for (; (inputChar > ' '); inputChar = getchar_unlocked())
        inputStr += inputChar;

    return true;
}


void fastOutput(int x){
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


int main() {
    std::string input1, input2;
    while(fastStringInput(input1)) {
        fastStringInput(input2);
        fastOutput(subsecuenciaComunMasLarga(input1, input2));
    }

    return 0;
}