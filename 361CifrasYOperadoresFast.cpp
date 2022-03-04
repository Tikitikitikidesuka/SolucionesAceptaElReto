#include <iostream>


#define NUM_DIGITS 5


typedef std::int_fast8_t c_bool;
typedef std::int_fast32_t c_int;
 

inline c_bool fastIntInput(int& number) {
    register std::int_fast8_t negativo = false;
    register std::int_fast8_t  input;
 
    // Clear noise on buffer
    for (; (input < '0' || input > '9') && input != '-'; input = getchar_unlocked())
        if(input == EOF) return false;
    
    if (input == '-') {
        negativo = true;
        input = getchar_unlocked();
    }

    number = 0;
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - '0';
    
    if(negativo)
        number *= -1;

    return true;
}


inline c_bool tryOperadores(c_int nums[NUM_DIGITS], c_int obj, c_int n, c_int val) {
    // Caso base
    if(n == NUM_DIGITS)
        return val == obj;
    
    c_int aceptado =
        tryOperadores(nums, obj, n + 1, val + nums[n]) ||
        tryOperadores(nums, obj, n + 1, val - nums[n]) ||
        tryOperadores(nums, obj, n + 1, val * nums[n]);
    
    if(nums[n] != 0 && val % nums[n] == 0) {
        aceptado = aceptado ||
        tryOperadores(nums, obj, n + 1, val / nums[n]);
    }

    return aceptado;
} 

inline c_bool tryOperadores(c_int nums[5], c_int obj) {
    return tryOperadores(nums, obj, 1, nums[0]);
}


int main() {
    c_int obj;
    c_int nums[NUM_DIGITS];
    while(fastIntInput(obj)) {
        for(c_int it = 0; it < NUM_DIGITS; ++it)
            fastIntInput(nums[it]);

        if(tryOperadores(nums, obj)) {
            putchar_unlocked('S');
            putchar_unlocked('I');
        } else {
            putchar_unlocked('N');
            putchar_unlocked('O');
        }
        putchar_unlocked('\n');
    }

    return 0;
}