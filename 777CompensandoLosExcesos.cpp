#include <iostream>

int gcd(int a, int b) {
  int temp;
  while (b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return(a);
}

int main() {
    int cases = 0;
    std::cin >> cases;
    
    for (int i = 0; i < cases; ++i) {
        int a, b;
        std::cin >> a >> b;
        std::cout << (a + b) / gcd(a, b) - 1 << "\n";
    }

    return 0;
}