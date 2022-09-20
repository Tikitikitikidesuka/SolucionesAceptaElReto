#include <iostream>
#include <unordered_map>
#include <string>

using std::unordered_map;
using std::string;

void addRey(unordered_map<string, int>& numReyes, const string& rey) {
	if(numReyes.count(rey)) {
		++numReyes.at(rey);
	} else {
		numReyes.insert(std::pair<string, int>(rey, 1));
	}
}

int getRey(const unordered_map<string, int>& numReyes, const string& rey) {
	if(numReyes.count(rey))
		return numReyes.at(rey);
	return 0;
}

int main() {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int oldReyes;
	std::cin >> oldReyes;
	while(oldReyes > 0) {
		unordered_map<string, int> numReyes;

		while(oldReyes--) {
			string inputRey;
			std::cin >> inputRey;
			addRey(numReyes, inputRey);
		}

		int newReyes;
		std::cin >> newReyes;
		while(newReyes--) {
			string inputRey;
			std::cin >> inputRey;
			std::cout << getRey(numReyes, inputRey) + 1 << '\n';
			addRey(numReyes, inputRey);
		}

		std::cout << '\n';

		std::cin >> oldReyes;
	}

	return 0;
}
