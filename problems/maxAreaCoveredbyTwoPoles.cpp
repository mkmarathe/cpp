#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &in) {
    int i = 0, j = in.size() - 1;
    int area = 0;

    while (i < j) {
        int tmp = min(in[i], in[j]) * (j - i);
        area = max(area, tmp);
        if (in[i] < in[j]) {
            i++;
        } else {
            j--;
        }
    }
    return area;
}

int main() {
    vector<int> a{1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(a);
}