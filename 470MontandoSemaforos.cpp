#include <iostream>
#include <stack>



int main() {
    char inputChar;
    int progress = 0, sum = 0;
    std::stack<char> progressStack;
    while(std::cin.get(inputChar)) {
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
                std::cout << sum << "\n";
                while(!progressStack.empty())
                    progressStack.pop();
                progress = 0;
                sum = 0;
                break;
        }
    }
    return 0;
}