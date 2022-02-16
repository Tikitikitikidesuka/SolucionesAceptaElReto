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


inline bool fastIntInput(int& number) {
    register int input;
 
    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked())
        if(input == EOF) return false;;

    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;

    return true;
}

inline bool fastStringInput(std::string& inputStr) {
    register char inputChar;
 
    //inputStr.clear();
    inputChar = getchar_unlocked();

    // Clear noise on buffer
    for (; (inputChar <= ' '); inputChar = getchar_unlocked())
        if(inputChar == EOF) return false;
 
    // Get number
    for (; (inputChar > ' '); inputChar = getchar_unlocked())
        inputStr += inputChar;

    return true;
}

inline void fastStringOutput(const std::string& outputString) {
    for(const char& c : outputString)
        putchar_unlocked(c);
}


int main() {
    int words;
    while(fastIntInput(words)) {
        stringMap strMap;
        vector<string> orderedKeys;
        orderedKeys.reserve(1000);
        while(words-- > 0) {
            string input;
            fastStringInput(input);
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
            fastStringOutput(strMap[strKey].getString());
            putchar_unlocked('\n');
        }

        putchar_unlocked('-');
        putchar_unlocked('-');
        putchar_unlocked('-');
        putchar_unlocked('\n');
    }
}