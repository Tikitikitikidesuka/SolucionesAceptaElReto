#include <iostream>

int main() {
	int size = 0;
	std::cin >> size;

	while(size != 0) {
		bool valid = true;

		for(int y = 0; y < size; ++y) {
			for(int x = 0; x < size; ++x) {
				int input = 0;
				std::cin >> input;

				if(valid)
					valid = input == (y == x);
			}
			
		}

		if(valid)
			std::cout << "SI\n";
		else
			std::cout << "NO\n";

		std::cin >> size;
	}

	return 0;
}
