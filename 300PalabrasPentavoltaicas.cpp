#include <iostream>


typedef int_fast8_t c_char;
typedef int_fast8_t c_bool;
typedef int_fast16_t c_int;


const c_char vocals[5] = {'a', 'e', 'i', 'o', 'u'};

int main() {
    c_int words = 0;
    std::cin >> words;
    
    while(words--) {
        c_char word[31];
        for(c_char counter = 0; counter < 30; ++counter)
            word[counter] = ' ';

        std::cin >> word;
        c_char letter = 'b';
        c_bool has_vocal[5] = {false,false,false,false,false};//0a,1e,2i,3o,4u
        for(c_char letter_counter = 0; letter != ' '; ++letter_counter){
            letter = word[letter_counter];
            for(c_char vocal_counter = 0; vocal_counter < 5; ++vocal_counter){
                if(letter == vocals[vocal_counter]){
                    has_vocal[vocal_counter] = true;
                }
            }
        }

        c_bool valid = true;
        for(c_char counter = 0; valid && counter < 5; ++counter){
            if(has_vocal[counter] == false){
                std::cout << "NO\n";
                valid = false;
            }
        }
        if(valid) 
            std::cout << "SI\n";
    }

    return 0;
}