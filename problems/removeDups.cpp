/* Remove duplicates from the vector in-place */

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(std::vector<int> &nums)
{
    // Handle empty array
    if (nums.size() == 0)
    {
        return 0;
    }

    // Start with first element as unique
    int k = 1;

    // Compare each element with previous
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main()
{
    {
        std::vector<int> a{1, 2, 3, 3, 3, 3, 4};
        std::cout << removeDuplicates(a) << std::endl;
    }
    {
        std::vector<int> a{1};
        std::cout << removeDuplicates(a) << std::endl;
    }
    {
        std::vector<int> a;
        std::cout << removeDuplicates(a) << std::endl;
    }
}