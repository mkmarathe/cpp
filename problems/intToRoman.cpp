#include <iostream>
#include <string>
#include <vector>
using namespace std;

string intToRoman(int integer) {
    vector<pair<int, string>> roman{
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},   {1, "I"}};
    string result;
    for (auto &[num, valStr] : roman) {
        while (integer >= num) {
            result += valStr;
            integer -= num;
        }
    }
    return result;
}
int main() {
    cout << intToRoman(1) << endl;
    cout << intToRoman(2) << endl;
    cout << intToRoman(3) << endl;
    cout << intToRoman(4) << endl;
    cout << intToRoman(1234) << endl;
    cout << intToRoman(1994) << endl;
}
