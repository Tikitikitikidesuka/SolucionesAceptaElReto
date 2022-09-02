#include <iostream>

typedef uint_fast32_t c_int ;

inline void fastIntInput(c_int& number) {
	register int_fast8_t input;

	number = 0;
	input = getchar_unlocked();

	// Clear noise on buffer
	for (; (input < '0' || input > '9'); input = getchar_unlocked());

	// Get number
	for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
		number = number * 10 + input - 48;
}

inline void fastIntOutput(c_int x){
	int_fast8_t buffer[35];
	register int_fast8_t i=0;
	do{
		buffer[i++] = (x % 10) + '0';
		x /= 10;
	} while(x);
	i--;
	while(i >= 0)
		putchar_unlocked(buffer[i--]);
	putchar_unlocked('\n');
}

inline c_int intCeilDiv(c_int a, c_int b) {
	c_int q = a / b;
	if(q * b < a) q += 1;
	return q;
}

int main() {
	c_int pruebas = 0;

	fastIntInput(pruebas);
	while(pruebas != 0) {
		c_int prev = 0;

		for(c_int prueba = 0; prueba < pruebas; ++prueba) {
			c_int n = 0, m = 0;
			std::cin >> n >> m;

			if(n <= prev) {
				c_int next = n + m * intCeilDiv(prev + 1 - n, m);
				prev = next;
			} else {
				prev = n;
			}
		}

		fastIntOutput(prev);

		fastIntInput(pruebas);
	}
	
	return 0;
}
