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


int main() {
    int examenes, maxRecordados;
    while(std::cin >> examenes >> maxRecordados) {
        int copiados = 0, pillados  = 0;

        RespuestaBuffer respuestas;

        std::queue<int> memoria;
        RespuestaBuffer respuestasRecordadas;

        while(examenes > 0) {
            int respuesta;
            std::cin >> respuesta;
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

        std::cout << copiados << " " << pillados << "\n";
    }
    return 0;
}