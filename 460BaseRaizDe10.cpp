#include <iostream>


int main() {
    std::int_fast8_t input;
    std::int_fast8_t state = false;
    input = getchar_unlocked();
    while(input != EOF) {
        if(input == '\n') {
            putchar_unlocked(input);
            input = getchar_unlocked();
            state = !state;
        }
        else{
            if(state) {
                putchar_unlocked('0');
            }
            else {
                putchar_unlocked(input);
                input = getchar_unlocked();
            }
            state = !state;
        }
    }
}