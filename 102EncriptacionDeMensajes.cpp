#include <iostream>


typedef std::int_fast8_t c_char;


inline void fastOutput(c_char x){
    char buffer[3];
    register int i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
        putchar_unlocked('\n');
}


inline bool esVocal(c_char character) {
    bool result = false;
    switch (character) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            result = true;
            break;
        }
    return result;
}

inline bool esLetra(c_char character) {
    return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z');
}

inline c_char decodificar(c_char character, c_char desfase) {
    if(!esLetra(character))
        return character;

    bool upper = character < 'a'; // Guardar si era mayuscula

    // Decodificar en minuscula
    c_char result = tolower(character) - desfase;
    if(result < 'a')
        result += 'z' - 'a' + 1;

    // Devolver a mayuscula si lo era
    if(upper)
        result += 'A' - 'a';
        
    return result;
}

inline void updateEstado(c_char character, c_char& estado) {
    switch (estado) {
    case 1:
        if(character == 'F')
            estado++;
        else
            estado = 0;
        break;
    case 2:
        if(character == 'I')
            estado++;
        else
            estado = 0;
        break;
    case 3:
        if(character == 'N')
            estado++;
        else
            estado = 0;
        break;
    default:
        estado = 0;
        break;
    }
}


int main() {
    bool done = false;
    c_char estado = 0;
    c_char input = ' ';

    while(!done) {
        while(input <= ' ')
            input = getchar_unlocked();

        c_char contador = 0;

        c_char desfase = tolower(input) - 'p';
        if(desfase < 0)
            desfase += 'z' - 'a' + 1;

        estado = 1;
        input = getchar_unlocked();
        while(input != '\n') {
            if(esLetra(input)) {
                c_char decoded = decodificar(input, desfase);

                updateEstado(decoded, estado);
                done = estado == 4;

                if(esVocal(tolower(decoded)))
                    contador++;
            }
            input = getchar_unlocked();
        }
        
        if(!done)
            fastOutput(contador);
    }

    return 0;
}