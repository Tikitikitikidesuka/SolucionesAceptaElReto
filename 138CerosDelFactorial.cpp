#include <iostream>


typedef std::int_fast32_t c_int;


inline void fastIntInput(c_int& number) {
    register char input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
}

inline void fastOutput(c_int x){
    char buffer[13];
    register int i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
        putchar_unlocked('\n');
}


inline c_int numZerosFact(c_int num) {
    c_int temp = num;
    c_int ceros = 0;
    while(num-- > 1) {
        temp = temp * num;
        while(temp % 10 == 0) {
            temp /= 10;
            ceros++;
        }
    
    }
    return ceros;
}


int main() {
    c_int casos;
    fastIntInput(casos);
    while(casos--) {
        c_int num;
        fastIntInput(num);
        std::cout << numZerosFact(num) << "\n";
    }
    return 0;
}