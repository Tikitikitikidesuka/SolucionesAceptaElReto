#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>


#define MAX_RESULT 1000


using std::stack;
using std::vector;
using std::unique;
using std::sort;


int main() {
    vector<int> results;
    stack<int> NP;
    NP.push(1);

    while(!NP.empty()) {
        int current = NP.top();
        NP.pop();

        results.push_back(current);

        if(current * 3 <= MAX_RESULT)
            NP.push(current * 3);
        if(current + 5 <= MAX_RESULT)
            NP.push(current + 5);
    }

    sort(results.begin(), results.end());
    results.erase(unique(results.begin(), results.end()), results.end());

    for(int result : results) {
        std::cout << result << " ";
    }
    std::cout << "\n";

    return 0;
}