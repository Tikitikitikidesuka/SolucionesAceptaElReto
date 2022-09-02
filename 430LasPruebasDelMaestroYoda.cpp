#include <iostream>

inline int intCeilDiv(int a, int b) {
	return a / b + (a % b != 0);
}

int main() {
	int pruebas = 0;

	std::cin >> pruebas;
	while(pruebas != 0) {
		int prev = 0;

		for(int prueba = 0; prueba < pruebas; ++prueba) {
			int n = 0, m = 0;
			std::cin >> n >> m;

			if(n <= prev) {
				int next = n + m * intCeilDiv(prev + 1 - n, m);
				prev = next;
			} else {
				prev = n;
			}
		}

		std::cout << prev << "\n";

		std::cin >> pruebas;
	}
	
	return 0;
}
