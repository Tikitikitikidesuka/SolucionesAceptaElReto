#include <iostream>


inline bool fastInput(int* number) {
    register int input;
 
    *number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9') && input != '-'; input = getchar_unlocked());
 
    // If number is negative clear remaining number from buffer and return false
    if(input == '-') {
        input = getchar_unlocked();
        for (; (input >= '0' && input <= '9'); input = getchar_unlocked());
        return false;
    }

    // If number is positive consume numbers from buffer to store them and return true
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        *number = *number * 10 + input - 48;
    
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
    // Input del primer ascensor
    int prev;
    while(fastInput(&prev)) {
        unsigned int recorrido = 0;

        // Input del resto de ascensores
        int input;
        while(fastInput(&input)) {
            int diff = input - prev;
            recorrido += (diff > 0) ? diff : -diff;

            prev = input;
        }

        // Output del recorrido
        fastOutput(recorrido);
    }
    
    return 0;
}