#include <algorithm>
#include <iostream>
#include <set>


using std::set;
typedef std::int_fast32_t c_int;


void insertarPareja(set<c_int>& vandada, set<c_int>::iterator& it, c_int val1, c_int val2) {
    vandada.insert(val1);
    vandada.insert(val2);
    if(val1 < *it && val2 < *it)
        --it;
    else if(val1 > *it && val2 > *it)
        ++it;
}


int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    c_int edadInit, parejas;
    std::cin >> edadInit >> parejas;
    while(edadInit != 0 || parejas != 0) {
        set<c_int> vandada;
        vandada.insert(edadInit);

        // Iterador siempre apuntara a la mediana
        c_int medIndex = 1;
        set<c_int>::iterator vandadaIt = vandada.begin();
        //std::cout << "Init: " << *vandadaIt << "\n";

        // Primera pareja aparte para solucionar el espacio de output
        if(parejas-- > 0) {
            c_int edad1, edad2;
            std::cin >> edad1 >> edad2;
            insertarPareja(vandada, vandadaIt, edad1, edad2);
            std::cout << *vandadaIt;
        }
        // Resto de casos se imprimen con espacio
        while(parejas--) {
            c_int edad1, edad2;
            std::cin >> edad1 >> edad2;
            insertarPareja(vandada, vandadaIt, edad1, edad2);
            std::cout << " " << *vandadaIt;
        }
        std::cout << "\n";

        std::cin >> edadInit >> parejas;
    }

    return 0;
}
