#include <stack>
#include <iostream>


using std::stack;
typedef std::uint_fast8_t c_int;


inline void fastIntInput(c_int& number) {
    register std::int_fast8_t input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
}


class Estado {
    public:
        c_int vainilla;
        c_int chocolate;
        c_int variacion[15];
        c_int variacionCount;

        Estado(c_int chocolate, c_int vainilla):
            chocolate(chocolate), vainilla(vainilla), variacionCount(0)
        {} 

        Estado(const Estado& oldEstado):
            chocolate(oldEstado.chocolate), vainilla(oldEstado.vainilla), variacionCount(oldEstado.variacionCount)
        {
            for(c_int i = 0; i < variacionCount; ++i) {
                variacion[i] = oldEstado.variacion[i];
            }
        }

        Estado addVainilla() {
            Estado newEstado = *this;
            newEstado.variacion[newEstado.variacionCount++] = 'V';
            newEstado.vainilla--;
            return newEstado;
        }

        Estado addChocolate() {
            Estado newEstado = *this;
            newEstado.variacion[newEstado.variacionCount++] = 'C';
            newEstado.chocolate--;
            return newEstado;
        }
};


inline void fastEstadoOutput(const Estado& estado) {
    for(c_int i = 0; i < estado.variacionCount; ++i) {
        putchar_unlocked(estado.variacion[i]);
    }
}


int main() {
    c_int casos;
    fastIntInput(casos);
    while(casos--) {
        c_int chocolate, vainilla;
        fastIntInput(chocolate);
        fastIntInput(vainilla);

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
                fastEstadoOutput(current);
                if(!CP.empty()) {
                    putchar_unlocked(' ');
                }
            }
        }
        putchar_unlocked('\n');
    }
}