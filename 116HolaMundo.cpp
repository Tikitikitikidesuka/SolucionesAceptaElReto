#include <iostream>
#include <cinttypes>

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    uint_fast8_t num;
    std::cin >> num;

    switch (num) {
        case '1':
            std::cout << "Hola mundo.\n";
            break;
        case '2':
            std::cout << "Hola mundo.\nHola mundo.\n";
            break;
        case '3':
            std::cout << "Hola mundo.\nHola mundo.\nHola mundo.\n";
            break;
        case '4':
            std::cout << "Hola mundo.\nHola mundo.\nHola mundo.\nHola mundo.\n";
            break;
        case '5':
            std::cout << "Hola mundo.\nHola mundo.\nHola mundo.\nHola mundo.\nHola mundo.\n";
            break;
    }

    return 0;
}