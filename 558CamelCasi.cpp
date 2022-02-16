#include <vector>
#include <iostream>
#include <unordered_map>


using std::size_t;
using std::string;
using std::vector;


class StringUpper {
    private:
        size_t numUpper;
        string stringVal;

        void updateNumUpper() {
            for(char& c : stringVal) {
                if(isupper(c))
                    numUpper++;
            }
        }

    public:
        StringUpper(): numUpper(0) {}

        StringUpper(const StringUpper& stringUpper): 
            numUpper(stringUpper.numUpper), stringVal(stringUpper.stringVal) 
        {}

        StringUpper(string newString): numUpper(0), stringVal(newString) {
            updateNumUpper();
        }

        const StringUpper& operator=(const StringUpper& stringUpper) {
            this->numUpper = stringUpper.numUpper;
            this->stringVal = stringUpper.stringVal;
            return *this;
        }

        const StringUpper& operator=(const string& stringNormal) {
            stringVal = stringNormal;
            updateNumUpper();
            return *this;
        }

        string getLower() const {
            string retString = stringVal; 
            for(char& c : retString)
                c = tolower(c);
            return retString;
        }

        string getString() const {
            return stringVal;
        }

        size_t getNumUpper() const {
            return numUpper;
        }
};

typedef std::unordered_map<string, StringUpper> stringMap;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int words;
    while(std::cin >> words) {
        stringMap strMap;
        vector<string> orderedKeys;
        while(words-- > 0) {
            string input;
            std::cin >> input;
            StringUpper inputUpper(input);

            string inputKey = inputUpper.getLower();
            orderedKeys.push_back(inputKey);

            if(strMap.count(inputKey)) {
                if(strMap[inputKey].getNumUpper() < inputUpper.getNumUpper()) {
                    strMap.at(inputKey) = inputUpper;
                }
            } else {
                strMap.insert(std::pair<string, StringUpper>(inputKey, inputUpper));
            }
        }

        for(const string& strKey : orderedKeys) {
            std::cout << strMap[strKey].getString() << "\n";
        }

        std::cout << "---\n";
    }
}