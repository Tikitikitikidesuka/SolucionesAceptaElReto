#include <iostream>


typedef float c_float;
typedef std::int_fast16_t c_int;


int main() {
    //   metros  km/h   segundos
    c_int dist, maxVel, tiempo;
    std::cin >> dist >> maxVel >> tiempo;
    while(dist != 0 || maxVel != 0 || tiempo != 0) {
        if(dist <= 0 || maxVel <= 0 || tiempo <= 0) {
            std::cout << "ERROR";
        } else {
            c_float velocidad = dist / (float) tiempo; // m/s
            velocidad /= 1000; // km/s
            velocidad *= 3600; // km/h
            if(velocidad > maxVel) {
                if(velocidad > maxVel * 1.2) {
                    std::cout << "PUNTOS";
                } else {
                    std::cout << "MULTA";
                }
            } else {
                std::cout << "OK";
            }
        }
        std::cout << "\n";

        std::cin >> dist >> maxVel >> tiempo;
    }

    return 0;
}