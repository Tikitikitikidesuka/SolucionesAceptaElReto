#include <unordered_set>
#include <algorithm>
#include <iostream>


std::unordered_set<std::string> elementos1 = {
        "H", "B", "C", "N", "O", "F", "P", "S", "K", "V", "Y", "I", "W", "U"
};

std::unordered_set<std::string> elementos2 = {
        "HE", "LI", "BE", "NE", "NA", "MG", "AL", "SI", "CL", "AR", "CA", "SC",
        "TI", "CR", "MN", "FE", "CO", "NI", "CU", "ZN", "GA", "GE", "AS", "SE",
        "BR", "KR", "RB", "SR", "ZR", "NB", "MO", "TC", "RU", "RH", "PD", "AG",
        "CD", "IN", "SN", "SB", "TE", "XE", "CS", "BA", "LA", "CE", "PR", "ND",
        "PM", "SM", "EU", "GD", "TB", "DY", "HO", "ER", "TM", "YB", "LU", "HF",
        "TA", "RE", "OS", "IR", "PT", "AU", "HG", "TL", "PB", "BI", "PO", "AT",
        "RN", "FR", "RA", "AC", "TH", "PA", "NP", "PU", "AM", "CM", "BK", "CF",
        "ES", "FM", "MD", "NO", "LR", "RF", "DB", "SG", "BH", "HS", "MT", "DS",
        "RG", "CN", "NH", "FL", "MC", "LV", "TS", "OG"
};


bool fraseElementos(std::string frase) {
    bool arr[1001];

    arr[0] = true;
    arr[1] = elementos1.count(frase.substr(0, 1));

    int length = frase.length();
    for(int i = 2; i <= length; i++) {
        bool contains1 = elementos1.count(frase.substr(i-1, 1));
        bool contains2 = elementos2.count(frase.substr(i-2, 2));
        if(contains1 && contains2) {
            arr[i] = arr[i-1] || arr[i-2];
        } else if(contains1) {
            arr[i] = arr[i-1];
        } else if(contains2) {
            arr[i] = arr[i-2];
        } else {
            arr[i] = false;
        }
    }

    return arr[length];
}

inline bool fastStringInput(std::string& inputStr) {
    register char inputChar;
 
    inputStr.clear();
    inputChar = getchar_unlocked();

    // Clear noise on buffer
    for (; (inputChar <= ' '); inputChar = getchar_unlocked())
        if(inputChar == EOF) return false;
 
    // Get number
    for (; (inputChar >= ' '); inputChar = getchar_unlocked()) {
        if(inputChar != ' ')
            inputStr += std::toupper(inputChar);
    }

    return true;
}

int main() {
    std::string input;
    // La funcion de input se ocupa de eliminar 
    // los espacios y ponerlo todo en mayuscula
    while(fastStringInput(input)) {
        if(fraseElementos(input)) {
            putchar_unlocked('S');
            putchar_unlocked('I');
        } else {
            putchar_unlocked('N');
            putchar_unlocked('O');
        }
        putchar_unlocked('\n');
    }
}