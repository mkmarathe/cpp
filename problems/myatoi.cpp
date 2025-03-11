#include <iostream>
#include <string>
using namespace std;

int32_t myAtoi(string in) {
    int sign = 1;
    bool hasSign = false;
    bool digitStarted = false;
    int32_t result = 0;
    for (int i = 0; i < in.size(); i++) {
        if (in[i] == ' ' && !hasSign && !digitStarted)
            continue;
        if ((in[i] == '-') && !hasSign && !digitStarted) {
            hasSign = true;
            sign = -1;
            continue;
        } else if ((in[i] == '+') && !hasSign && !digitStarted) {
            hasSign = true;
            continue;
        }

        if (in[i] < '0' || in[i] > '9') {
            break;
        }
        digitStarted = true;
        // printf("%c=", in[i]);
        // printf("checking %d\n", result);
        int digit = (in[i] - '0');

        if (result > INT32_MAX / 10 ||
            ((result == INT32_MAX / 10) && (digit * sign > 7))) {
            // cout << "checking MAX\n";
            return INT32_MAX;
        }

        if (result < INT32_MIN / 10 ||
            ((result == INT32_MIN / 10) && (digit * sign < -8))) {
            // cout << "checking MIN\n";
            return INT32_MIN;
        }

        result = abs(result * 10) * sign + abs(digit) * sign;
    }
    return result;
}
int main() {
    cout << myAtoi("-99l8") << endl;
    cout << myAtoi("+99") << endl;
    cout << myAtoi("-99") << endl;
    cout << myAtoi("1746384713") << endl;
    cout << myAtoi("-3174836471") << endl;
    cout << myAtoi("2147483648") << endl;
    cout << myAtoi("0-1") << endl;
    cout << myAtoi("+2147483647") << endl;
    cout << myAtoi("-2147483648") << endl;
    cout << myAtoi("-91283472332") << endl;
}
