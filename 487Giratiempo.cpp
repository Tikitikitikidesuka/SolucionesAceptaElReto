#include <iostream>

#define SECS_IN_AN_HOUR 3600

typedef uint_fast64_t c_int;

int main() {
	std::cin.tie(NULL);
	std::cin.sync_with_stdio(false);

	int casos;
	std::cin >> casos;

	while(casos--) {
		c_int horas;
		std::cin >> horas;

		c_int prevExtra, extra = 0;

		do {
			prevExtra = extra;
			extra = (horas + prevExtra) / SECS_IN_AN_HOUR;
		} while(extra != prevExtra);

		std::cout << horas + extra << "\n";
	}

	return 0;
}
