#include <iostream>
#include <string>
#include <vector>

using namespace std;

int x(int position, int row) {
    int cycle = (row * 2) - 2;
    position = position % cycle;
    return std::min(position, cycle - (position % (cycle)));
}

string convert(string &s, int numRows) {
    if (numRows == 0)
        return "";
    if (numRows == 1)
        return s;
    vector<string> vec(min(numRows, (int)s.size()));
    for (int i = 0; i < s.size(); i++) {
        vec[x(i, numRows)].push_back(s[i]);
    }
    string result;
    for (auto v : vec) {
        result += v;
    }
    return result;
}

int main() {

    string s{"abcdefghijklmnopqrstuvwxyz"};
    cout << convert(s, 26) << endl;
    cout << endl;
    cout << convert(s, 5) << endl;
    cout << endl;
    cout << convert(s, 7) << endl;
    cout << endl;
    cout << convert(s, 10) << endl;
}