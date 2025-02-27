#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if (m > n) {
        return findMedianSortedArrays(nums2, nums1);
    }
    int right = m;
    int left = 0;
    while (left <= right) {
        int partition1 = (left + right) / 2;
        int partition2 = (m + n + 1) / 2 - partition1;
        // A: nums1's left part max, B: nums1's right part min
        // C: nums2's left part max, C: nums2's right part min
        int A = partition1 == 0 ? INT_MIN : nums1[partition1 - 1];
        int B = partition1 == m ? INT_MAX : nums1[partition1];
        int C = partition2 == 0 ? INT_MIN : nums2[partition2 - 1];
        int D = partition2 == n ? INT_MAX : nums2[partition2];
        // final check to see if all left parts are smaller than right parts;
        if ((A <= D) && (C <= B)) {
            if ((m + n) % 2 == 0) {
                return (std::max(A, C) + std::min(B, D)) / 2.0;
            } else {
                return std::max(A, C);
            }
        }
        // disregard nums1s higher elements, choose partition;s left side.
        if (A > D) {
            right = partition1 - 1;
        } else { // disregard nums1 lower elements, choose partition's right
                 // side.
            left = partition1 + 1;
        }
    }
    return 0.0;
}

int main() {
    {
        std::vector<int> a{1, 3, 4, 7};
        std::vector<int> b{8, 9, 11, 12};
        std::cout << findMedianSortedArrays(a, b) << std::endl;
    }
}