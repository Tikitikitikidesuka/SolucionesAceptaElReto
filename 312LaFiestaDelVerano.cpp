#include <iostream>

int64_t gcd(int64_t a, int64_t b) {
	if (a < b) {
		int64_t temp = a;
		a = b;
		b = temp;
	}

	while (b != 0) {
		int64_t temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

int main() {
	std::cin.tie(NULL);
	std::cout.sync_with_stdio(false);

	int64_t local_gcd;
	std::cin >> local_gcd;

	while (local_gcd != 0) {
		int64_t input;
		std::cin >> input;

		int64_t sum = local_gcd;

		while (input != 0) {
			sum += input;

			if (local_gcd >= input)
				local_gcd = gcd(local_gcd, input);
			else
				local_gcd = gcd(input, local_gcd);

			std::cin >> input;
		}

		std::cout << sum / local_gcd << "\n";

		std::cin >> local_gcd;
	}

	return 0;
}
