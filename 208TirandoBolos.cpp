#include <iostream>

int64_t bolosTotales(int64_t a, int64_t b) {
	return a * (a + 1) / 2;
}

int64_t bolosTirados(int64_t a, int64_t b) {
	return (a - b + 2) * (a - b + 1) / 2;
}

int64_t bolosRestantes(int64_t a, int64_t b) {
	return (2*b*a - b*b + 3*b - 2*a - 2) / 2;
}

int main() {
	int64_t a, b;
	std::cin >> a >> b;

	while(a != 0 || b != 0) {
		std::cout << bolosRestantes(a, b) << "\n";
		std::cin >> a >> b;
	}

	return 0;
}
