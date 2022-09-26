#include <iostream>

int main() {
	int casos = 0;
	std::cin >> casos;

	while(casos--) {
		int size = 0;
		int stark = 0;
		int peter = 0;
		int intervalo = 0;

		std::cin >> size >> stark >> peter >> intervalo;

		--stark;
		--peter;

		bool starkVivo = true;
		bool peterVivo = true;

		// Procesamiento

		int pos = 0;
		const int obSize = size / 2;
		while(size > obSize) {
			pos += intervalo;
			if(pos >= size) pos %= size;

			if(starkVivo) {
				if(pos < stark) {
					--stark;
				} else if(pos == stark) {
					starkVivo = false;
				}
			}

			if(peterVivo) {
				if(pos < peter)  {
					--peter;
				} else if(pos == peter) {
					peterVivo = false;
				}
			}

			--size;

		}

		// Output

		if(starkVivo && !peterVivo) {
			std::cout << "No quiero irme, Sr. Stark!\n";
		} else if(!starkVivo && peterVivo) {
			std::cout << "No quiero irme, Peter!\n";
		} else {
			std::cout << "No hay abrazo\n";
		}
	}

	return 0;
}
