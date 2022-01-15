#include <iostream>


void fastInput(int* number) {
    register char input;
 
    *number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        *number = *number * 10 + input - 48;
}


void fastOutput(unsigned int x){
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
    int pasos[10], numPasos;

    int escalones;
    fastInput(&escalones);
    while(escalones != 0) {
        escalones++;

        fastInput(&numPasos);
        for(int pasoCntr = 0; pasoCntr < numPasos; pasoCntr++)
            fastInput(pasos + pasoCntr);
        
        unsigned int numFormas[100];
        numFormas[0] = 1;
        numFormas[1] = 1;

        for(int escalonCntr = 2; escalonCntr < escalones; escalonCntr++) {
            numFormas[escalonCntr] = 0;
            for(int pasoCntr = 0; pasoCntr < numPasos; pasoCntr++) {
                if(escalonCntr - pasos[pasoCntr] >= 0) {
                    numFormas[escalonCntr] += numFormas[escalonCntr - pasos[pasoCntr]];
                    numFormas[escalonCntr] %= 1000000007;
                }
            }
        }

        fastOutput(numFormas[escalones -1]);

        fastInput(&escalones);
    }
}