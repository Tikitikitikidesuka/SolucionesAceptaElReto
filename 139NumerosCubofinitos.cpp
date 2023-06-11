#include <iostream>
#include <vector>

const int MAX_DIGITS = 7;
const int MAX_NUMBER = MAX_DIGITS * 9 * 9 * 9;

int sumCubedDigits(int x) {
  int sum = 0;

  while (x != 0) {
    int digit = x % 10;
    sum += digit * digit * digit;
    x /= 10;
  }

  return sum;
}


bool cubofinito(int x) {
  std::vector<bool> visited(MAX_NUMBER, false);

  int num = x;
  std::cout << num;

  if (num > MAX_NUMBER) {
    num = sumCubedDigits(num);
    std::cout << " - " << num;
  }

  while (num != 1 && !visited[num - 1]) {
    visited[num - 1] = true;
    num = sumCubedDigits(num);
    std::cout << " - " << num;
  }

  return num == 1;
}

int main() {
  int num = 0;
  std::cin >> num;

  while (num != 0) {
    bool valid = cubofinito(num);
    std::cout << " -> " << (valid ? "cubifinito" : "no cubifinito") << ".\n";
    std::cin >> num;
  }

  return 0;
}
