/* Remove all occurances of val and move them to end of the array,
    and return number of valid elements. Needs to be done in place. */
#include <iostream>
#include <vector>

int removeElement(std::vector<int> &nums, int val)
{
    int j = 0; // track end of valid elements.
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

int main()
{
    {
        std::vector<int> a{3, 5, 3, 6, 5, 3, 1};
        std::cout << removeElement(a, 3) << std::endl;
    }
    {
        std::vector<int> a;
        std::cout << removeElement(a, 3) << std::endl;
    }
}