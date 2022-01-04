#include <iostream>


int main() {
    int casos;
    std::cin >> casos;
    for(int cntr = 0; cntr < casos; cntr++) {
        int pag;
        std::cin >> pag;
        if(pag % 2 == 0) std::cout << pag+1 << "\n";
        else std::cout << pag-1 << "\n";
    }
    return 0;
}