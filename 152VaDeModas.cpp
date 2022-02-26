#include <iostream>
#include <unordered_map>


using std::unordered_map;
typedef std::int_fast16_t c_int;


inline void fastIntInput(c_int& number) {
    register bool negativo = false;
    register std::int_fast8_t  input;
 
    // Clear noise on buffer
    for (; (input < '0' || input > '9') && input != '-'; input = getchar_unlocked());
    
    if (input == '-') {
        negativo = true;
        input = getchar_unlocked();
    }

    number = 0;
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
    
    if(negativo)
        number *= -1;
}

inline void fastOutput(c_int x){
    std::int_fast8_t negative = x < 0;
    if(x < 0) {
        putchar_unlocked('-');
        negative = true;
        x *= -1;
    }

    std::int_fast8_t buffer[35];
    register std::int_fast8_t i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
        putchar_unlocked('\n');
}


int main() {
    c_int casos;
    fastIntInput(casos);
    while(casos) {
        c_int moda = 0;
        c_int maxReps = 0;
        unordered_map<c_int, c_int> repeticiones;
        while(casos--) {
            c_int input;
            fastIntInput(input);

            if(!repeticiones.count(input))
                repeticiones.insert({input, 0});

            if(++repeticiones[input] > maxReps) {
                maxReps = repeticiones[input];
                moda = input;
            }
        }

        fastOutput(moda);

        fastIntInput(casos);
    }

    return 0;
}