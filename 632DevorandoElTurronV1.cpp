#include <iostream>
#include <vector>


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


int maxTurron(std::vector<int> hilera1, std::vector<int> hilera2, int tiempo);

int main() {
    int numHilera1, numHilera2, tiempo;
    while(fastInput(numHilera1) &&  fastInput(numHilera2) && fastInput(tiempo)) {
        int cntr, useless;
        
        useless = numHilera1 - tiempo;
        for(cntr = 0; cntr < useless; cntr++) {
            int sink;
            fastInput(sink);
        }
        std::vector<int> hilera1;
        for(; cntr < numHilera1; cntr++) {
            int input;
            fastInput(input);
            hilera1.push_back(input);
        }

        useless = numHilera2 - tiempo;
        for(cntr = 0; cntr < useless; cntr++) {
            int sink;
            fastInput(sink);
        }
        std::vector<int> hilera2;
        for(; cntr < numHilera2; cntr++) {
            int input;
            fastInput(input);
            hilera2.push_back(input);
        }

        fastOutput(maxTurron(hilera1, hilera2, tiempo));
    }
    return 0;
}


inline int getBackIndex(const std::vector<int>& vector, int index) {
    return vector.size() -1 - index;
}

inline void initTurronBuffer(const std::vector<int>& hilera, int tiempo, int& num, int& sum) {
    num = sum = 0;
    while(sum < tiempo && num < hilera.size()) {
        sum += hilera[getBackIndex(hilera, num)];
        num++;
    }
    if(sum > tiempo) {
        num--;
        sum -= hilera[getBackIndex(hilera, num)];
    }
}

inline void updateTurronBuffer(const std::vector<int>& hilera, int tiempo, int& num, int& sum) {
    while(sum > tiempo && num >= 0) {
        sum -= hilera[getBackIndex(hilera, num-1)];
        num--;
    }
}

int maxTurron(std::vector<int> hilera1, std::vector<int> hilera2, int tiempo) {
    int num1, sum1;
    int num2, sum2;
    initTurronBuffer(hilera1, tiempo, num1, sum1);
    initTurronBuffer(hilera2, tiempo, num2, sum2);

    int piezas = 0;
    while(num1 != 0 || num2 != 0) {
        if(num1 >= num2) {
            int poped_val = hilera1.back();
            tiempo -= poped_val;
            sum1 -= poped_val;
            num1--;
            hilera1.pop_back();
            updateTurronBuffer(hilera2, tiempo, num2, sum2);
        } else {
            int poped_val = hilera2.back();
            tiempo -= poped_val;
            sum2 -= poped_val;
            num2--;
            hilera2.pop_back();
            updateTurronBuffer(hilera1, tiempo, num1, sum1);
        }
        piezas++;
    }
    return piezas;
}