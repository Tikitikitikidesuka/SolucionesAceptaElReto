#include <iostream>
#include <cinttypes>

inline void fastIntInput(uint_fast32_t & number) {
    register int_fast8_t input;

    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());

    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
}

inline void fastIntOutput(uint_fast32_t x){
    int_fast8_t buffer[35];
    register int_fast8_t i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
    putchar_unlocked('\n');
}

int main() {
    uint_fast32_t casos = 0;
    fastIntInput(casos);

    while (casos--) {
        uint_fast32_t rocas = 0;
        fastIntInput(rocas);

        uint_fast32_t p = 0, r = 0;

        uint_fast32_t prev_roca = 0;
        for (uint_fast32_t i = 0; i < rocas; ++i) {
            uint_fast32_t roca;
            fastIntInput(roca);

            uint_fast32_t n = roca - prev_roca;

            if (n == r) {
                --r;
            } else if (n > r) {
                if (n > p) {
                    p = n;
                    r = n - 1;
                } else {
                    p = p + 1;
                    r = p;
                }
            }

            prev_roca = roca;
        }

        fastIntOutput(p);
    }

    return 0;
}
