#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    string str;
    int rMax = 0;
    int cMax = 0;
    // bogus character b/n each character (including outer boundaries)
    str.push_back('|');
    for (auto a : s) {
        str.push_back(a);
        str.push_back('|');
    }

    for (int center = 0; center < str.length(); center++) {
        int radius = 0;
        while (((center - (radius + 1)) >= 0) &&
               ((center + (radius + 1)) < str.length()) &&
               str[(center - (radius + 1))] == str[(center + (radius + 1))]) {
            radius++;
        }
        if (radius > rMax) {
            rMax = radius;
            cMax = center;
        }
    }
    return s.substr((cMax - rMax) / 2, rMax);
}

int main() {
    string s{"babad"};
    cout << s << endl;
    cout << longestPalindrome(s) << endl;
}