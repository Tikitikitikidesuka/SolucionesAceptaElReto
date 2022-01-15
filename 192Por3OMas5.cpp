#include <iostream>


bool fastInput(int* number) {
    register int input;
 
    *number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());
 
    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        *number = *number * 10 + input - 48;

    return *number != 0;
}


int main() {
    int input;
    while(fastInput(&input)) {
        bool arr[20000];

        arr[0] = false;
        arr[1] = true;

        for(int num = 2; num <= input; num++)
            arr[num] = (num % 3 == 0 && arr[num / 3]) || (num - 5 >= 0 && arr[num - 5]);
        
        if(arr[input]) {
            putchar_unlocked('S');
            putchar_unlocked('I');
        } else {
            putchar_unlocked('N');
            putchar_unlocked('O');
        }
        putchar_unlocked('\n');
    }
    return 0;
}