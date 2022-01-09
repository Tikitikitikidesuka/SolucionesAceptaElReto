#include <iostream>
#include <stack>


inline void fastOutput(int x){
    char buffer[35];
    register int i=0;
    do{
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while(x);
    i--;
    while(i >= 0) putchar_unlocked(buffer[i--]);
        putchar_unlocked('\n');
}

int main() {
    char inputChar = getchar_unlocked();
    register int progress = 0, sum = 0;
    std::stack<char> progressStack;
    while(inputChar != EOF) {
        switch(inputChar) {
            case 'R':
                if(progress == 0) { // If expected
                    progress++;
                } else { // If unexpected
                    progressStack.push(progress);
                    progress = 1;
                }
                break;

            case 'A':
                if(progress == 1) { // If expected
                    progress++;
                } else { // If unexpected
                    progress = 0;
                    while(!progressStack.empty())
                        progressStack.pop();
                }
                break;

            case 'V':
                if(progress == 2) { // If expected
                    sum++;
                    if(progressStack.empty())
                        progress = 0;
                    else {
                        progress = progressStack.top();
                        progressStack.pop();
                    }
                } else { // If unexpected
                    progress = 0;
                    while(!progressStack.empty())
                        progressStack.pop();
                }
                break;

            default: // End of input
                fastOutput(sum);
                while(!progressStack.empty())
                    progressStack.pop();
                progress = 0;
                sum = 0;
                break;
        }

        inputChar = getchar_unlocked();
    }
    return 0;
}