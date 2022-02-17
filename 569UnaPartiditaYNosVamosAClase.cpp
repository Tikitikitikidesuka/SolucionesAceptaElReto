#include <iostream>


using std::size_t;
typedef uint16_t timeMin;


inline void fastSizetInput(size_t& number) {
    register int input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
}

inline void fastTimeInput(timeMin& number) {
    register int input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
}

inline void fastTimeOutput(timeMin x){
    char buffer[5];
    register int i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
        putchar_unlocked('\n');
}


constexpr const timeMin INICIO = 8*60 + 0; // 08:00
constexpr const timeMin FINAL  = 14*60 + 0; // 14:00

int main() {
    size_t casos;
    fastSizetInput(casos);
    while(casos--) {
        timeMin jugado = 0;
        timeMin prev = INICIO;

        size_t clases;
        timeMin durPartida;
        fastTimeInput(durPartida);
        fastSizetInput(clases);
        while(clases--) {
            timeMin hours, mins;
            fastTimeInput(hours);
            fastTimeInput(mins);
            timeMin initTime, endTime;
            initTime = hours * 60 + mins;
            fastTimeInput(endTime);
            endTime += initTime;

            timeMin localJugado = initTime - prev;
            if(localJugado >= durPartida)
                jugado += localJugado;

            prev = endTime;
        }
        timeMin finalJugado = FINAL - prev;
        if(finalJugado >= durPartida)
            jugado += finalJugado;

        fastTimeOutput(jugado);
    }
    return 0;
}