#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    int p1 = m - 1;
    int p2 = n - 1;
    int p = m + n - 1;
    if (p2 < 0)
    { // nums2 is empty. do nothing
        return;
    }
    /* case with both vectors are non empty AND nums1 empty handled together*/
    while (p2 >= 0)
    {
        if ((p1 < 0) || (nums1[p1] < nums2[p2]))
        {
            nums1[p] = nums2[p2];
            p2--;
        }
        else
        {
            nums1[p] = nums1[p1];
            p1--;
        }
        p--;
    }
}

void print(const string &msg, vector<int> &v)
{
    cout << msg;
    for (auto a : v)
    {
        cout << a << " ";
    }
    cout << endl;
}
int main()
{

    {
        cout << "******** TEST 1 ********" << endl;
        vector<int> nums1{0, 5, 6, 7, 0, 0, 0};
        vector<int> nums2{1, 3, 5};
        print("nums1: ", nums1);
        print("nums2: ", nums2);
        merge(nums1, 4, nums2, 3);
        print("Reuslt: ", nums1);
    }

    {
        cout << "******** TEST 2 ********" << endl;
        vector<int> nums1{1};
        vector<int> nums2{};
        print("nums1: ", nums1);
        print("nums2: ", nums2);
        merge(nums1, 1, nums2, 0);
        print("Reuslt: ", nums1);
    }

    {
        cout << "******** TEST 3 ********" << endl;
        vector<int> nums1{};
        vector<int> nums2{3};
        print("nums1: ", nums1);
        nums1.resize(1);  //Needed to hold the result;
        print("nums2: ", nums2);
        merge(nums1, 0, nums2, 1);
        print("Reuslt: ", nums1);
    }

    return 0;
}