#include <iostream>
#include <string>
#include <vector>

using namespace std;

int x(int position, int row) {
    int cycle = (row * 2) - 2;
    position = position % cycle;
    return std::min(position, cycle - (position % (cycle)));
}

int y(int position, int row) {
    int cycle = (row * 2) - 2;
    int repeat = position / cycle;
    int offset = position % cycle;
    if (offset > (row - 1)) {
        return (offset - (row - 1)) + (repeat * (row - 1));
    } else {
        return (repeat * (row - 1));
    }
}

int noOfColumns(int n, int rows) {
    int cycle = (rows * 2) - 2;
    // total elements n,  we need ceil(n/cycle) * (1+cycle-rows) columns
    // ceil needed because, we allocate for full cycles.
    return ((n + cycle - 1) / cycle) * (1 + cycle - rows);
}

string convert(string &s, int numRows) {
    if (numRows == 0)
        return "";
    if (numRows == 1)
        return s;

    int size = noOfColumns(s.length(), numRows);
    printf("columns allocated %d\n", size);
    vector<vector<int>> vec(numRows, vector<int>(size));
    for (int i = 0; i < s.length(); i++) {
        int row = x(i, numRows);
        int col = y(i, numRows);
        vec[row][col] = s[i]; // this takes to retain  grid pattern info
        // printf("(%d,%d)\n", row, col);
    }
    s.clear();
    for (int i = 0; i < numRows; i++) {
        for (auto v : vec[i]) {
            if (v) {
                printf("%c ", v);
                s.push_back(v);

            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    cout << endl;
    return s;
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