#include <iostream>
#include <unordered_map>
#include <cstdint>

int main() {
    uint64_t lights = 0;
    std::cin >> lights;

    while (lights != 0) {
        uint64_t disemination = 0;
        std::unordered_map<uint64_t, uint64_t> last_color_idx;

        for (uint64_t i = 0; i < lights; ++i) {
            uint64_t color;
            std::cin >> color;

            if (last_color_idx.count(color))
                disemination += i - last_color_idx[color];
            last_color_idx[color] = i;
        }

        std::cout << disemination << "\n";

        std::cin >> lights;
    }

    return 0;
}