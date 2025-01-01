#include <iostream>

int main() {
    int year, sighting;
    std::cin >> year >> sighting;
    
    while (year != 0 || sighting != 0) {
        std::cout << "[" 
            << year + 74 * sighting
            << " .. " << year + 79 * sighting
            << "]\n";
        
        std::cin >> year >> sighting;
    }

    return 0;
}