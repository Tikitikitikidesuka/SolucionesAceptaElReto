#include <iostream>

int main() {
	int casos = 0;
	std::cin >> casos;

	while(casos--) {
		int m, p, t;
		std::cin >> m >> p >> t;

		std::cout << t - std::max(t - p, m) + 1 << '\n';
	}

	return 0;
}
