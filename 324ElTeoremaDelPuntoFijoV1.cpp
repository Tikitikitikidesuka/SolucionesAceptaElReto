#include <iostream>
#include <vector>


using std::vector;
typedef std::int_fast32_t c_int;


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

inline void fastIntOutput(c_int x){
    std::int_fast8_t buffer[35];
    register std::int_fast8_t i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
        putchar_unlocked('\n');
}


inline vector<c_int> desplazamiento(const vector<c_int>& input) {
    vector<c_int> desplazamientos(input.size(), 0);
    for(c_int it = 0; it < input.size(); ++it) {
        c_int disp = it + 1 - input[it];
        if(disp < 0) disp += input.size();
        desplazamientos[input[it]-1] = disp;
    }
    return desplazamientos;
}

inline c_int getPeriodo(c_int pos, const vector<c_int>& desplazamientos) {
    c_int periodo = 1;
    c_int movPos = (pos + desplazamientos[pos]) % desplazamientos.size();
    while(movPos != pos) {
        movPos += desplazamientos[movPos];
        movPos %= desplazamientos.size();
        ++periodo;
    }

    return periodo;
}

inline c_int gcd(c_int a, c_int b) {
    c_int swap;
    while (b != 0) {
        swap = a % b;

        a = b;
        b = swap;
    }
    return a;
}

inline c_int lcm(c_int a, c_int b) {
    return a  / gcd(a, b) * b;
}


int main() {
    c_int longitud;
    fastIntInput(longitud);
    while(longitud != 0) {
        vector<c_int> inputs;
        inputs.reserve(longitud);
        for(c_int it = 0; it < longitud; ++it) {
            c_int input;
            fastIntInput(input);
            inputs.push_back(input);
        }

        vector<c_int> desplazamientos = desplazamiento(inputs);

        vector<c_int> periodos;
        periodos.reserve(longitud);
        for(c_int it = 0; it < longitud; ++it)
            periodos.push_back(getPeriodo(it, desplazamientos));

        c_int lcmResult = periodos[0];
        for(c_int it = 1; it < longitud; ++it)
            lcmResult = lcm(lcmResult, periodos[it]);

        fastIntOutput(lcmResult);

        fastIntInput(longitud);
    }

    return 0;
}