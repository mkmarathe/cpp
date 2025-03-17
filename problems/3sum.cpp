#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int> &in) {
    vector<vector<int>> result;

    int left = 0, right = 0;

    sort(in.begin(), in.end());
    for (int i = 0; i < in.size() - 2; i++) {
        if ((i > 0) && (in[i] == in[i - 1]))
            continue;
        left = i + 1;
        right = in.size() - 1;
        while (left < right) {
            int sum = in[i] + in[left] + in[right];
            if (sum == 0) {
                result.push_back(vector<int>{in[i], in[left], in[right]});
                while ((left < right) && (in[left] == in[left + 1]))
                    left++;
                while ((left < right) && (in[right] == in[right - 1]))
                    right--;
                left = left + 1;
                right = right - 1;
            } else if (sum > 0) {
                right = right - 1;
            } else {
                left = left + 1;
            }
        }
    }
    return result;
}
void printVector(const vector<int> &vec) {
    cout << "[ ";
    for (const auto &element : vec) {
        cout << element << " ";
    }
    cout << "]" << endl;
}

int main() {
    {
        vector<int> a{5, -2, -2, -4, 0, 6, -3, -5, 8, 2};
        printVector(a);
        for (auto &v : threeSum(a)) {
            printVector(v);
            cout << endl;
        }
    }
    {
        vector<int> a{-1, 0, 1, 2, -1, -4};
        printVector(a);
        for (auto &v : threeSum(a)) {
            printVector(v);
            cout << endl;
        }
    }
    {
        vector<int> a{-1, 2, -1, -1, 2, -1, -1, 2, -1, -1, 2, -1, -1, 2, -1};
        printVector(a);
        for (auto &v : threeSum(a)) {
            printVector(v);
            cout << endl;
        }
    }
}
