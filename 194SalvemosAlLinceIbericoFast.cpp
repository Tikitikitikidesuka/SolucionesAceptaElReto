#include <iostream>


inline int fastStringInput(char* inputStr) {
    register char inputChar;
 
    inputChar = getchar_unlocked();

    // Clear noise on buffer
    for (; (inputChar <= ' '); inputChar = getchar_unlocked());
 
    // Get number
    int cntr = 0;
    for (; (inputChar > ' '); inputChar = getchar_unlocked())
        inputStr[cntr++] = inputChar;
    
    return cntr;
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

inline void fastIntInput(int* number) {
    register int input;
 
    *number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        *number = *number * 10 + input - 48;
}


int main() {
    int veces;
    fastIntInput(&veces);
    while(veces--) {
        char input[10000];
        int length = fastStringInput(input);

        int puentes = 0;
        for(int cntr = 0; cntr < length; cntr++) {
            if(input[cntr] == '.') {
                ++puentes;
                cntr += 2;
            }
        }
        
        fastOutput(puentes);
    }
}