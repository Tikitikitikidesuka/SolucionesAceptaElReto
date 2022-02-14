#include <iostream>


using std::int32_t;


inline void fastInput(int32_t& number) {
    register int32_t input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
}

inline void fastOutput(int32_t x){
    char buffer[35];
    register int32_t i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
        putchar_unlocked('\n');
}


const int32_t K = 31543;

inline int32_t fastExp(int32_t base, int32_t exp) {
    base = base % K;
    int32_t sol = 1;
    while(exp) {
        if(exp & 1) {   // If 1
            sol = (sol * base) % K;
        }
        base = (base * base) % K;
        exp = exp >> 1;
    }
    return sol;
}

int main() {
    int32_t base, exp;
    fastInput(base);
    fastInput(exp);
    while(base != 0 || exp != 0) {
        fastOutput(fastExp(base, exp));

        fastInput(base);
        fastInput(exp);
    }
}