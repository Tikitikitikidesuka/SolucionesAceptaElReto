#include <deque>
#include <string>
#include <iostream>
#include <unordered_map>


using std::deque;
using std::string;
using std::unordered_map;
typedef std::int_fast16_t c_int;
typedef std::uint_fast8_t c_char;


inline bool fastDigitInput(c_char& number) {
    register c_char input;
 
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked())
        if(input < ' ') return false;

    number = input - '0';
    return true;
}


const unordered_map<c_int, std::string> PAISES = {
        {0,     "EEUU"},
        {380,   "Bulgaria"},
        {50,    "Inglaterra"},
        {539,   "Irlanda"},
        {560,   "Portugal"},
        {70,    "Noruega"},
        {759,   "Venezuela"},
        {850,   "Cuba"},
        {890,   "India"}
    };


class CodigoBarras {
    private:
        deque<c_char> values;

    public:
        c_char size() {
            return values.size();
        }

        bool getInput() {
            values.clear();

            c_char input;
            while(fastDigitInput(input))
                values.push_back(input);
            
            if(values.size() == 1 && values.back() == 0)
                return false;

            if(values.size() > 8) { // EAN-13
                while(values.size() < 13) {
                    values.push_front(0);
                }
            } else {                // EAN-8
                while(values.size() < 8) {
                    values.push_front(0);
                }
            }

            return true;
        }

        bool esValido() {
            if(values.size() > 13)
                return false;

            c_int suma = 0;
            bool impar = true;
            std::deque<c_char>::reverse_iterator it = values.rbegin();
            c_char control = *it;
            for(++it; it != values.rend(); ++it) {
                if(impar)
                    suma += *it * 3;
                else
                    suma += *it;
                impar = !impar;
            }
            return (suma + values.back()) % 10 == 0;
        }

        string getPais() {
            c_int pais = 0;
            bool encontrado = false;
            for(std::deque<c_char>::iterator it = values.begin(); !encontrado && it != values.end(); ++it) {
                pais = pais * 10 + *it;
                if(PAISES.count(pais))
                    encontrado = true;
            }
            if(encontrado)
                return PAISES.at(pais);
            return "Desconocido";
        }
};


int main() {
    CodigoBarras codigo;
    while(codigo.getInput()) {
        bool valido = codigo.esValido();
        std::cout << (valido ? "SI" : "NO");
        if(valido && codigo.size() > 8) {
            std::cout << " " << codigo.getPais();
        }
        std::cout << "\n";
    }
    return 0;
}