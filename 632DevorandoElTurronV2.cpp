#include <iostream>


inline void sinkInput() {
    char input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
    
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked());
}

inline bool fastInput(int& number) {
    register int input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked())
        if(input == EOF) return false;
    
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;

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


int maxTurron(int* hilera1, int hilera1Size, int* hilera2, int hilera2Size, int tiempo);

int main() {
    int numHilera1, numHilera2, tiempo;
    while(fastInput(numHilera1) &&  fastInput(numHilera2) && fastInput(tiempo)) {
        int useless;
        
        useless = numHilera1 - tiempo;
        for(int cntr = 0; cntr < useless; cntr++) {
            sinkInput();
        }
        int hilera1[200000];
        int hilera1Size = (numHilera1 < tiempo) ? numHilera1 : tiempo;
        for(int cntr = 0; cntr < hilera1Size; cntr++) {
            int input;
            fastInput(input);
            hilera1[cntr] = input;
        }

        useless = numHilera2 - tiempo;
        for(int cntr = 0; cntr < useless; cntr++) {
            sinkInput();
        }
        int hilera2[200000];
        int hilera2Size = (numHilera2 < tiempo) ? numHilera2 : tiempo;
        for(int cntr = 0; cntr < hilera2Size; cntr++) {
            int input;
            fastInput(input);
            hilera2[cntr] = input;
        }

        fastOutput(maxTurron(hilera1, hilera1Size, hilera2, hilera2Size, tiempo));
    }
    return 0;
}


inline int getBackIndex(int hileraSize, int index) {
    return hileraSize - 1 - index;
}

inline void initTurronBuffer(int* hilera, int hileraSize, int tiempo, int& num, int& sum) {
    num = sum = 0;
    while(sum < tiempo && num < hileraSize) {
        sum += hilera[getBackIndex(hileraSize, num)];
        num++;
    }
    if(sum > tiempo) {
        num--;
        sum -= hilera[getBackIndex(hileraSize, num)];
    }
}

inline void updateTurronBuffer(int* hilera, int hileraSize, int tiempo, int& num, int& sum) {
    while(sum > tiempo && num >= 0) {
        sum -= hilera[getBackIndex(hileraSize, num-1)];
        num--;
    }
}

inline int maxTurron(int* hilera1, int hilera1Size, int* hilera2, int hilera2Size, int tiempo) {
    int num1, sum1;
    int num2, sum2;
    initTurronBuffer(hilera1, hilera1Size, tiempo, num1, sum1);
    initTurronBuffer(hilera2, hilera2Size, tiempo, num2, sum2);

    int piezas = 0;
    while(num1 != 0 || num2 != 0) {
        if(num1 >= num2) {
            int poped_val = hilera1[hilera1Size-1];
            tiempo -= poped_val;
            sum1 -= poped_val;
            num1--;
            hilera1Size--;
            updateTurronBuffer(hilera2, hilera2Size, tiempo, num2, sum2);
        } else {
            int poped_val = hilera2[hilera2Size-1];
            tiempo -= poped_val;
            sum2 -= poped_val;
            num2--;
            hilera2Size--;
            updateTurronBuffer(hilera1, hilera1Size, tiempo, num1, sum1);
        }
        piezas++;
    }
    return piezas;
}