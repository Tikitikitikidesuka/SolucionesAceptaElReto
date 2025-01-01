#include <iostream>
#include <vector>

int main() {
    int num_elems = 0;
    std::cin >> num_elems;
    
    while (num_elems != 0) {
        int64_t in;
        std::cin >> in;

        int count = 1;
        int64_t max = in;

        for (int i = 1; i < num_elems; ++i) {
            std::cin >> in;

            max = std::max(max, in);
            if (in < max) count = 0;
            else count += 1;
        }
        
        std::cout << count << "\n";

        std::cin >> num_elems;
    }

    return 0;
}

// Memory limit exceeded
int mle_main() {
    int num_elems = 0;
    std::cin >> num_elems;
    
    while (num_elems != 0) {
        std::vector<int64_t> elems;
        elems.reserve(num_elems);

        for (int i = 0; i < num_elems; ++i) {
            int64_t in;
            std::cin >> in;
            elems.push_back(in);
        }
        
        int i = num_elems - 1;
        while (i - 1 >= 0 && elems[i - 1] <= elems[i]) i -= 1;
        
        int j = i;
        while (--i >= 0) {
            while (j < num_elems && elems[i] > elems[j]) ++j;
        }
        
        std::cout << num_elems - j << "\n";
        
        std::cin >> num_elems;
    }

    return 0;
}