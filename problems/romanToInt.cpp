#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int romanToInt(const string &in) {

    int result = 0;
    int prev = 0;
    int curr = 0;
    for (int i = in.size() - 1; i >= 0; i--) {
        prev = curr;
        if (in[i] == 'I')
            curr = 1;
        if (in[i] == 'V')
            curr = 5;
        if (in[i] == 'X')
            curr = 10;
        if (in[i] == 'L')
            curr = 50;
        if (in[i] == 'C')
            curr = 100;
        if (in[i] == 'D')
            curr = 500;
        if (in[i] == 'M')
            curr = 1000;
        if (prev > curr)
            result -= curr;
        else
            result += curr;
    }
    return result;
}
int main() {

    cout << romanToInt("III") << endl;
    cout << romanToInt("LVIII") << endl;
    cout << romanToInt("MCCXXXIV") << endl;
    cout << romanToInt("MCMXCIV") << endl;
}
