#include <iostream>
#include <stdio.h>


int main() {
    int casos;
    std::cin >> casos;
    for(int caso = 0; caso < casos; caso++) {
        int dia, mes, anio;
        scanf("%d/%d/%d", &dia, &mes, &anio);
        
        if(anio % 4 == 0) {
            if(mes > 2 || (mes == 2 && dia >= 29))
                printf("29/02/%04d\n", (anio/4 +1)*4);
            else
                printf("29/02/%04d\n", anio);
        } else {
            printf("29/02/%04d\n", (anio/4 +1)*4);
        }
    }
    return 0;
}