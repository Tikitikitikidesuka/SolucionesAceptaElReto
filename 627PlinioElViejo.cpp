#include <iostream>
#include <stdio.h>


const int MES[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
    int diaN, mesN, anioN, aniosL, mesesL, dias;
    scanf("%d/%d/%d %d %d %d", &diaN, &mesN, &anioN, &aniosL, &mesesL, &dias);
    while(diaN != 0 || mesN != 0 || anioN != 0 || aniosL != 0 || mesesL != 0 || dias != 0) {
        mesesL += aniosL * 12;
        dias += mesesL * 28 + diaN;

        int anio = anioN;
        int mes = mesN;
        std::cout << dias << " vs " <<  ((mes == 2 && anio%4 == 0) ? MES[mes-1]+1 : MES[mes-1]) << "\n";
        while(dias > ((mes == 2 && anio%4 == 0) ? MES[mes-1]+1 : MES[mes-1])) {
            if(mes == 2 && anio%4 == 0)
                dias -= MES[mes-1]+1;
            else
                dias -= MES[mes-1];

            mes++;
            if(mes > 12) {
                anio++;
                mes = 1;
            }
        }

        printf("%02d/%02d/%04d\n", dias, mes, anio);

        scanf("%d/%d/%d %d %d %d", &diaN, &mesN, &anioN, &aniosL, &mesesL, &dias);
    }
}