#include <iostream>
#include <cmath>

const int MAX_NUM = 100000;

int main() {
	int pi[MAX_NUM + 1];
	int maxPi = 3;
	pi[0] = 0;
	pi[1] = 0;
	pi[2] = 1;

	int primes[MAX_NUM + 1];
	int maxPrime = 1;
	primes[0] = 2;
	
	int n, m;
	std::cin >> n >> m;
	while(n != 0 || m != 0) {
		for(int i = maxPi; i <= n; ++i) {
			bool isPrime = true;

			for(int p = 0; isPrime && p < maxPrime && primes[p] <= sqrt(i); ++p) {
				isPrime = i % primes[p] != 0;
			}

			if(isPrime) {
				primes[maxPrime] = i;
				++maxPrime;

				pi[i] = pi[i - 1] + 1;
			} else {
				pi[i] = pi[i - 1];
			}
		}
		
		maxPi = n + 1;

		double error = fabs(pi[n] / static_cast<double>(n) - 1 / log(n));
		double maxError = 1 / pow(10, m);

		if(error > maxError) {
			std::cout << "Mayor\n";
		} else if (error < maxError) {
			std::cout << "Menor\n";
		} else {
			std::cout << "Igual\n";
		}

		std::cin >> n >> m;
	}

	return 0;
}
