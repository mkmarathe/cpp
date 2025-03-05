#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

std::tuple<int, int> max(const vector<int> a) {
    int i = 0, r = 0, c = 0;
    for (auto v : a) {
        if (r < v) {
            r = v;
            c = i;
        }
        i++;
    }
    return std::make_tuple(c, r);
}

string longestPalindrome(string s) {
    string str;
    // int rMax = 0, cMax = 0;
    //  bogus character b/n each character (including outer boundaries)
    str.push_back('|');
    for (auto a : s) {
        str.push_back(a);
        str.push_back('|');
    }
    vector<int> palindromRadii(str.length(), 0);

    int oldCenter = 0;
    int oldRadius = 0;
    int radius = 0;

    for (int center = 0; center < str.length();) {

        while (((center - (radius + 1)) >= 0) &&
               ((center + (radius + 1)) < str.length()) &&
               str[(center - (radius + 1))] == str[(center + (radius + 1))]) {
            radius++;
        }
        palindromRadii[center] = radius;
        oldCenter = center;
        oldRadius = radius;
        center++;
        radius = 0;

        while (center <= (oldCenter + oldRadius)) {
            int mirroredCenter = oldCenter - (center - oldCenter);
            int maxMirrorRadius = oldCenter + oldRadius - center;
            if (palindromRadii[mirroredCenter] < maxMirrorRadius) {
                // palindrome at mirrorcenter is contained with palindrom with
                // oldcenter, so update radius for center.
                palindromRadii[center] = palindromRadii[mirroredCenter];
                center++;
            } else if (palindromRadii[mirroredCenter] > maxMirrorRadius) {
                // palindrom at mirrorcenter is goes beyond palindrome with
                // oldcenter, so palindrom at center is for sure ends at right
                // edge of palindrom with oldcenter.
                palindromRadii[center] = maxMirrorRadius;
                center++;

            } else { // if(palindromRadii[center] > maxMirrorRadius)
                // palindrome with center is exactly upto palindrom with
                // oldcenter, cant say how big is palindrom at center, its
                // atleast maxMirrorRadius big.
                radius = maxMirrorRadius;
                break;
            }
        }
    }
    auto [cMax, rMax] = max(palindromRadii);
    return s.substr((cMax - rMax) / 2, rMax);
}

int main() {
    string s{"aacabdkacaa"};
    cout << s << endl;
    cout << longestPalindrome(s) << endl;
}