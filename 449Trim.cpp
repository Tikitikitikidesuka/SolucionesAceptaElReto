#include <iostream>
#include <algorithm>

#define MAX_LENGTH 80

void removeConsecutiveDuplicates(std::string& str) {
	str.erase(std::unique(str.begin(), str.end()), str.end());
}

int necessaryTrims(const std::string& str) {
	int solMatrix[MAX_LENGTH][MAX_LENGTH + 1];

	solMatrix[0][0] = 1;
	solMatrix[0][1] = 0;

	for(int j = 1; j < str.length(); ++j) {
		solMatrix[j][j] = 1;
		solMatrix[j][j+1] = 0;

		for(int i = j - 1; i >= 0; --i) {
			if(str[j] == str[i]) {
				solMatrix[j][i] = solMatrix[j-1][i+1] + 1;
			} else {
				solMatrix[j][i] = std::min(
					solMatrix[j-1][i],
					solMatrix[j][i+1]
				) + 1;
			}
		}
	}

	return solMatrix[str.length() - 1][0];
}

int main() {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	std::string text;

	while(std::cin >> text) {
		removeConsecutiveDuplicates(text);
		std::cout << necessaryTrims(text) << "\n";
	}

	return 0;
}
