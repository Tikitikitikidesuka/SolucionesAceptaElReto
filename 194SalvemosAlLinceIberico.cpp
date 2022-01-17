#include <iostream>


int main() {
    int veces;
    std::cin >> veces;
    while(veces--) {
        std::string input;
        std::cin >> input;
        int puentes = 0;
        for(int cntr = 0; cntr < input.length(); cntr++) {
            if(input[cntr] == '.') {
                puentes++;
                cntr += 2;
            }
        }
        std::cout << puentes << std::endl;
    }
}