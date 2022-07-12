#include <iostream> /// for IO operations
#include <vector>

uint64_t binarySearch(std::vector<uint64_t> arr, uint64_t val)
{
    uint64_t low = 0;               // set the lowest point of the vector.
    uint64_t high = arr.size() - 1; // set the highest point of the vector.

    while (low <= high)
    {
        uint64_t m = low + (high - low) / 2; // set the pivot point

        if (val == arr[m])
        {
            return m;
        }
        else if (val < arr[m])
        {
            high = m - 1;
        }
        else
        {
            low = m + 1;
        }
    }
    return -1; // if val is not in the array, return -1.
}