#include <iostream>


typedef std::int_fast16_t c_int;


int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    c_int casos;
    std::cin >> casos;
    while(casos--) {
        c_int a, b;
        std::cin >> a >> b;
        std::cout << a * 100 / (a + b) << "\n";
    }

    return 0;
}