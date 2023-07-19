#include <iostream>

int main() {
    int vertices = 0;

    std::cin >> vertices;
    while (vertices > 0) {
        int from, to, edges = 0;

        std::cin >> from >> to;
        while (from != 0 || to != 0) {
            ++edges;

            std::cin >> from >> to;
        }

        std::cout << edges - vertices + 1 << "\n";

        std::cin >> vertices;
    }

    return 0;
}