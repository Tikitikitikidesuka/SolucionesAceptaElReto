#include <string>
#include <iostream>
#include <unordered_map>


using std::string;
using std::unordered_map;
typedef std::int_fast16_t c_int;


inline bool fastDigitInput(c_int& number) {
    register std::int_fast8_t input;
 
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
        c_int length;
        c_int arr[13];

    public:
        c_int getLength() {
            return length;
        }

        c_int getDigit(c_int digit) {
            return arr[length - 1 - digit];
        }

        c_int getControlDigit() {
            return arr[length - 1];
        }

        bool getInput() {
            length = 0;
            c_int input;

            /*
            // Quitar los ceros de la izquierda
            while(fastDigitInput(input) && input == 0);
            if(input == 0) return false;
            */

            // Guardar el resto del codigo
            while(fastDigitInput(input))
                arr[length++] = input;

            return length != 1;
        }

        bool esValido() {
            c_int suma = 0;
            bool impar = true;
            for(c_int digito = 1; digito < length; ++digito) {
                if(impar)
                    suma += getDigit(digito) * 3;
                else
                    suma += getDigit(digito);
                impar = !impar;
            }
            return (10 - suma % 10)%10 == getControlDigit();
        }

        string getPais() {
            c_int pais = getDigit(length -1);
            bool encontrado = false;
            for(c_int digitos = 1; digitos <= 3; ++digitos) {
                if(PAISES.count(pais))
                    encontrado = true;
                else
                    pais = pais * 10 + getDigit(length -1 -digitos);
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
        if(valido && codigo.getLength() > 8) {
            std::cout << " " << codigo.getPais();
        }
        std::cout << "\n";
    }
    return 0;
}