#include <iostream>
#include <string>

int tienePositivo(const std::string& resultados, int from, int to) {
	for(int i = from; i <= to; ++i) {
		if(resultados[i] == '1') {
			return true;
		}
	}

	return false;
}

int pruebasNecesarias(const std::string& resultados, int from, int to) {
	// Caso base
	if(from == to || !tienePositivo(resultados, from, to)) {
		return 1;
	}

	// Caso recursivo
	int pivote = (from + to) / 2;

	int izq = pruebasNecesarias(resultados, from, pivote);
	int der = pruebasNecesarias(resultados, pivote + 1, to);
		
	return 1 + izq + der;
}

int pruebasNecesarias(const std::string& resultados) {
	return pruebasNecesarias(resultados, 0, resultados.length() - 1);
}

int main() {
	int muestras = 0;
	std::cin >> muestras;

	while(muestras != 0) {
		std::string resultados;
		std::cin >> resultados;

		std::cout << pruebasNecesarias(resultados) << '\n';

		std::cin >> muestras;
	}

	return 0;
}
