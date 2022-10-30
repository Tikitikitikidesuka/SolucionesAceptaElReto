#include <iostream>

int main() {
	int casos;
	std::cin >> casos;

	while(casos--) {
		int anyo;
		std::cin >> anyo;

		if(anyo % 100 == 0) {
			if(anyo % 400 == 0) std::cout << "29\n";
			else std::cout << "28\n";
		} else {
			if(anyo % 4 == 0) std::cout << "29\n";
			else std::cout << "28\n";
		}
	}

	return 0;
}
