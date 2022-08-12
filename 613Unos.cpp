#include <iostream>

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
	while(std::cin >> input) {
		std::cout << unos(input) << '\n';
	}
	return 0;
}
