#include <iostream>

int main() {
    int64_t prev_in, in;

    std::cin >> in;
    while (in != 0) {
        int64_t max_sum = in;

        while (in != 0) {
            prev_in = in;
            std::cin >> in;
            max_sum = std::max(max_sum, in + prev_in);
        }

        std::cout << max_sum << "\n";

        std::cin >> in;
    }

    return 0;
}