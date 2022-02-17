#include <iostream>


int main() {
    int numInputs;
    std::cin >> numInputs;
    while(numInputs--) {
        int num;
        std::cin >> num;
        std::cout << num / 3 << "\n";
    }
}