#include <stack>
#include <string>
#include <iostream>


using std::stack;
using std::string;
typedef std::int_fast16_t c_int;
typedef std::int_fast16_t c_int_big;


class Estado {
    public:
        c_int vainilla;
        c_int chocolate;
        string variacion;

        Estado(c_int chocolate, c_int vainilla):
            chocolate(chocolate), vainilla(vainilla)
        {} 

        Estado addVainilla() {
            Estado newEstado = *this;
            newEstado.variacion += 'V';
            newEstado.vainilla--;
            return newEstado;
        }

        Estado addChocolate() {
            Estado newEstado = *this;
            newEstado.variacion += 'C';
            newEstado.chocolate--;
            return newEstado;
        }
};


int main() {
    c_int_big casos;
    std::cin >> casos;
    while(casos--) {
        c_int chocolate, vainilla;
        std::cin >> chocolate >> vainilla;

        stack<Estado> CP;
        CP.push(Estado(chocolate, vainilla));

        while(!CP.empty()) {
            Estado current = CP.top();
            CP.pop();

            bool leaf = true;
            if(current.vainilla > 0) {
                CP.push(current.addVainilla());
                leaf = false;
            }
            if(current.chocolate > 0) {
                CP.push(current.addChocolate());
                leaf = false;
            }
            if(leaf) {
                std::cout << current.variacion;
                if(!CP.empty()) {
                    std::cout << " ";
                }
            }
        }
        std::cout << "\n";
    }
}