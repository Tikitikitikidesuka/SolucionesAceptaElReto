#include <iostream>
#include <cstdint>
#include <cmath>

uint32_t arithmeticSum(uint32_t x) {
	return x * (x + 1) / 2;
}

uint32_t reverseArithmeticSum(uint32_t x) {
	return ceil((sqrt(1 + 4 * 2 * x) - 1) / 2.0);
}

uint32_t maxPiramidHeight(uint32_t pieces) {
	uint32_t i = 1, j = reverseArithmeticSum(pieces);

	uint32_t usedPieces = arithmeticSum(j) - arithmeticSum(i - 1);
	while (usedPieces != pieces) {
		if (usedPieces < pieces) usedPieces += ++j;
		else if (usedPieces > pieces) usedPieces -= i++;
	}

	return j - i + 1;
}


int main() {
	std::cout << reverseArithmeticSum(10000000);

	uint32_t pieces;

	while (std::cin >> pieces) {
		std::cout << maxPiramidHeight(pieces) << "\n";
	}

	return 0;
}
