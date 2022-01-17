#include <algorithm>
#include <iostream>


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
    int casos;
    fastIntInput(&casos);
    while(casos > 0) {
        int input, iter = 0;
        fastIntInput(&input);

        bool valid = false;
        int inputCheck = input;
        int prev = inputCheck % 10;
        inputCheck /= 10;
        for(int inputCntr = 2; !valid && inputCntr >= 0; --inputCntr) {
            char digit = inputCheck % 10;
            valid = digit != prev;
            inputCheck /= 10;
            prev = digit;
        }

        if(valid) {
            while(input != 6174) {
                char tempArr[4];
                for(int inputCntr = 3; inputCntr >= 0; --inputCntr) {
                    tempArr[inputCntr] = input % 10;
                    input /= 10;
                }

                // Get number with sorted digits
                std::sort(tempArr, tempArr + 4);
                int sortedAsc = 0, sortedDes = 0;
                for(int inputCntr = 0; inputCntr < 4; ++inputCntr) {
                    sortedAsc = sortedAsc * 10 + tempArr[inputCntr];
                    sortedDes = sortedDes * 10 + tempArr[3 - inputCntr];
                }

                // Difference
                input = sortedDes - sortedAsc;

                iter++;
            }

            fastOutput(iter);
        } else {
            fastOutput(8);
        }

        casos--;
    }
}