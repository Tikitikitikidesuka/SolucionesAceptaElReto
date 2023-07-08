/*
Posiciones: 1 6 7 11 16
---------------------------
Saltos (n): 1 5 1 4 5
r:        0 0 4 4 3 6
p:        0 1 5 5 5 6

Si n = r:
    r := r - 1
Si n > r:
    Si n > p:
        r := n - 1
        p := n
    Si no:
        r := p + 1
        p := p + 1
*/

#include <iostream>

int main() {
    int casos = 0;
    std::cin >> casos;

    while (casos--) {
        int rocas = 0;
        std::cin >> rocas;

        int p = 0, r = 0;

        int prev_roca = 0;
        for (int i = 0; i < rocas; ++i) {
            int roca;
            std::cin >> roca;

            int n = roca - prev_roca;

            if (n == r) {
                --r;
            } else if (n > r) {
                if (n > p) {
                    p = n;
                    r = n - 1;
                } else {
                    p = p + 1;
                    r = p;
                }
            }

            prev_roca = roca;
        }

        std::cout << p << "\n";
    }

    return 0;
}
