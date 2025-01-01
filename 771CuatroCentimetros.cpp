#include <iostream>

int main() {
    int casos = 0;
    std::cin >> casos;
    
    while (casos--) {
        int i = 0;
        std::cin >> i;

        std::cout << (i * 4) << "\n";
    }

    return 0;
}