#include <iostream>
#include <queue>


#define MAX_RESPUESTA 100000


class RespuestaBuffer {
    private:
        int max = 0;
        int buffer[MAX_RESPUESTA];

        void clearUpTo(int to) {
            for(int cntr = 0; cntr <= to; cntr++) {
                this->buffer[cntr] = false;
            }
        }

        void updateMax(int num) {
            if(num > this->max) 
                this->max = num;
        }
    
    public:
        RespuestaBuffer() {
            clearUpTo(MAX_RESPUESTA);
        }

        // Devuelve True si la respuesta se ha marcado. False si ya estaba marcada.
        bool set(int num) {
            bool notSet = !this->buffer[num];
            if(notSet)
                this->buffer[num] = true;
            updateMax(num);
            return notSet;
        }

        void reset(int num) {
            this->buffer[num] = false;
        }

        bool increase(int num) {
            bool alreadySet = this->buffer[num] != 0;
            this->buffer[num]++;
            updateMax(num);
            return alreadySet;
        }

        bool decrease(int num) {
            this->buffer[num]--;
            if(this->buffer[num] < 0) {
                this->buffer[num] = 0;
            }
            return isSet(num);
        }

        bool isSet(int num) {
            return this->buffer[num];
        }

        void clear() {
            clearUpTo(this->max);
        }

        friend std::ostream& operator<<(std::ostream& out, const RespuestaBuffer& data) {
            for(int cntr = 0; cntr <= data.max; cntr++) {
                out << data.buffer[cntr] << "_";
            }
            out << "\n";
            return out;
        }
};


inline bool fastPositiveInputNoisyStdin(int* number) {
    register int input;
 
    *number = 0;
    input = getchar_unlocked();

    if(input == EOF)
        return false;

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        *number = *number * 10 + input - 48;
    
    return true;
}


inline void fastOutput(int x){
    char buffer[35];
    register int i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
}


int main() {
    int examenes, maxRecordados;
    while(fastPositiveInputNoisyStdin(&examenes)) {
        fastPositiveInputNoisyStdin(&maxRecordados);
        int copiados = 0, pillados  = 0;

        RespuestaBuffer respuestas;

        std::queue<int> memoria;
        RespuestaBuffer respuestasRecordadas;

        while(examenes > 0) {
            int respuesta;
            fastPositiveInputNoisyStdin(&respuesta);
            respuesta--;

            if(!respuestas.set(respuesta)) {
                copiados++;
            }

            memoria.push(respuesta);
            if(respuestasRecordadas.increase(respuesta))
                pillados++;

            if(memoria.size() > maxRecordados) {
                respuestasRecordadas.decrease(memoria.front());
                memoria.pop();
            }

            examenes--;

            //std::cout << respuestasRecordadas;
        }

        fastOutput(copiados);
        putchar_unlocked(' ');
        fastOutput(pillados);
        putchar_unlocked('\n');
    }
    return 0;
}