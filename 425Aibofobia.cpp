#include <iostream>
#include <string>


int numAibofobia(const std::string& palabra) {
    int matriz[100][100];

    // Caso base
    for(int j = 0; j < palabra.length(); j++) {
        for(int i = j; i < palabra.length(); i++) {
            matriz[i][j] = 0;
        }
    }

    // Caso recursivo
    for(int j = 1; j < palabra.length(); j++) {
        for(int i = 1; i <= j; i++) {
            if(palabra[j - i] == palabra[j])
                matriz[j - i][j] = matriz[j - i + 1][j - 1];
            else
                matriz[j - i][j] = std::min(matriz[j - i + 1][j], matriz[j - i][j - 1]) + 1;
        }
    }

    return matriz[0][palabra.length() - 1];
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


int main() {
    std::string input;
    while(fastStringInput(input)) {
        fastOutput(numAibofobia(input));
    }
}