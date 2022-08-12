#include <iostream>

inline bool fastIntInput(int& number) {
    register std::int_fast8_t  input;
 
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

inline void fastIntOutput(int x){
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

int unos(int base) {
	int unos = 0;
	int resto = 0;
	int dividendo = 1;

	while(dividendo < base) {
		dividendo = dividendo * 10 + 1;
		++unos;
	}

	do {
		resto = dividendo % base;
		dividendo = resto * 10 + 1;
		++unos;
	} while(resto != 0); 
	
	return unos;
}

int main() {
	int input;
	while(fastIntInput(input)) {
		fastIntOutput(unos(input));
	}
	return 0;
}