#include <iostream>

typedef int64_t c_int;

c_int cerosFactorial(c_int num) {
	c_int cincos = 0;

	c_int div5 = num / 5;
	while(div5 > 0) {
		cincos += div5;
		div5 /= 5;
	}

	return cincos;
}

c_int busquedaBinariaFactorial(c_int ceros) {
	c_int max = ceros * 5;
	c_int min = ceros / 5;
	c_int pivote = (max + min) / 2;
	c_int cerosPivote = cerosFactorial(pivote);

	if(ceros == 0)
		return 0;

	if(cerosPivote == ceros)
		return pivote;

	while(min < max && cerosPivote != ceros) {
		if(ceros > cerosPivote) {
			min = pivote + 1;
		} else if(ceros < cerosPivote) {
			max = pivote - 1;
		}

		pivote = (max + min) / 2;
		cerosPivote = cerosFactorial(pivote);
	}

	if(min > max)
		return -1;

	while(pivote >= 0 && cerosFactorial(--pivote) == ceros);
		return pivote + 1;
}

int main() {
	c_int mult, ceros;
	std::cin >> mult >> ceros;

	while(mult != 0 || ceros != 0) {
	c_int fact = busquedaBinariaFactorial(ceros);
	if(fact != -1) {
		if(fact == 0) ++fact;

		c_int diff = fact % mult;
		if(diff != 0) fact += mult - diff;

		if(cerosFactorial(fact) == ceros) {
			std::cout << fact << "\n";
		} else {
			std::cout << "NINGUNO\n";
		}
	} else {
		std::cout << "NINGUNO\n";
	}

	std::cin >> mult >> ceros;
	}

	return 0;
}
