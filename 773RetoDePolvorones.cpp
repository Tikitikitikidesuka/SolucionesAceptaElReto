#include <iostream>
#include <vector>

int main() {
    int safe_max, types;
    std::cin >> safe_max >> types;

    while (safe_max != 0 || safe_max != 0) {
        std::vector<int> max_per_type, tray_per_type;

        for (int i = 0; i < types; ++i) {
            int in;
            std::cin >> in;
            max_per_type.push_back(in);
        }
        
        for (int i = 0; i < types; ++i) {
            int in;
            std::cin >> in;
            tray_per_type.push_back(in);
        }

        int acc = 0;
        for (int i = 0; i < types; ++i) {
            if (tray_per_type[i] <= max_per_type[i]) {
                acc += tray_per_type[i];
            } else {
                acc = safe_max + 1;
                break;
            }
        }

        if (acc <= safe_max) {
            std::cout << "SI\n";
        } else {
            std::cout << "NO\n";
        }

        std::cin >> safe_max >> types;
    }
}