#include <iostream>
using namespace std;
int32_t reverse(int32_t x) {
    int32_t result = 0;
    while (x != 0) {
        int mod = x % 10;
        x = x / 10;
        if (result > INT32_MAX / 10 ||
            ((result == INT32_MAX / 10) && (mod > 7)))
            return 0;
        if (result < INT32_MIN / 10 ||
            ((result == INT32_MIN / 10) && (mod < -8)))
            return 0;
        result = result * 10 + mod;
    }
    return result;
}

int main() {
    int32_t x = -1746384713;
    cout << reverse(x) << endl;
    x = -19;
    cout << reverse(x) << endl;
    x = 19;
    cout << reverse(x) << endl;
}