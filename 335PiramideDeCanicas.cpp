#include <iostream>

typedef uint_fast64_t c_int;

c_int canicas_piramide(c_int nivel) {
	return nivel * (nivel + 1) * ((2 * nivel + 1) + 3) / 12;
}

int main() {
	int casos;
	std::cin >> casos;

	while(casos--) {
		c_int nivel;
		std::cin >> nivel;
		std::cout << canicas_piramide(nivel) << "\n";
	}

	return 0;
}
