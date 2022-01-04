#include <iostream>


bool checkTriangulo(int a, int b, int c) {
    if (a + b <= c || a + c <= b || b + c <= a)
        return false;
    else
        return true;
}

int main() {
    int casos;
    std::cin >> casos;
    for(int caso = 0; caso < casos; caso++) {
        int numTiras;
        std::cin >> numTiras;

        int max1 = 0, max2 = 0, max3 = 0;
        for(int tira = 0; tira < numTiras; tira++) {
            int longitud;
            std::cin >> longitud;

            if(longitud > max1) {
                if(longitud > max2) {
                    if(longitud > max3) {
                        if(checkTriangulo(max2, max3, longitud)) {
                            max1 = max2;
                            max2 = max3;
                            max3 = longitud;
                        }
                    } else {
                        max1 = max2;
                        max2 = longitud;
                    }
                } else {
                    max1 = longitud;
                }
            }
        }
        std::cout << max1 + max2 + max3 << "\n";
    } 
    return 0;
}