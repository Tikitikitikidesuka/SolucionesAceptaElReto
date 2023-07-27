#include <iostream>
#include <cinttypes>

inline void intInput(uint_fast16_t& number) {
    register std::int_fast8_t input;

    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());

    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
}

inline void intOutput(uint_fast16_t x){
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

int alpha_morse_dots(char c) {
    const int alpha_dots[] =
            { 5,  9, 11,  7,  1,  9,
              9,  7,  3, 13,  9,  9,
              7,  5, 11, 11, 13,  7,  5,
              3,  7,  9,  9, 11, 13, 11};

    int dots = 0;

    if (c == '!')
        dots = 19;
    else if (c == '?')
        dots = 15;
    else
        dots = alpha_dots[c - 'A'];

    return dots;
}

uint_fast16_t line_morse_dots() {
    uint_fast16_t dots = 0;

    char c = ' ', prev_c = ' ';
    c = getchar_unlocked();
    while (c >= ' ') {
        if (c == ' ') {
            dots += 5;
        } else {
            dots += alpha_morse_dots(c);
            if (prev_c != ' ') dots += 3;
        }

        prev_c = c;
        c = getchar_unlocked();
    }

    return dots;
}

int main() {
    uint_fast16_t cases = 0;
    intInput(cases);

    while (cases--) {
        intOutput(line_morse_dots());
    }

    return 0;
}