#include <iostream>
#include <cinttypes>

inline void fastIntInput(uint_fast16_t & number) {
    register std::int_fast8_t input;

    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());

    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
}

inline void fastIntOutput(uint_fast16_t x){
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
    uint_fast16_t vertices = 0;

    fastIntInput(vertices);
    while (vertices != 0) {
        uint_fast16_t input, edges = 0;

        fastIntInput(input);
        fastIntInput(input);
        while (input != 0) {
            ++edges;

            fastIntInput(input);
            fastIntInput(input);
        }

        fastIntOutput(edges - vertices + 1);

        fastIntInput(vertices);
    }

    return 0;
}