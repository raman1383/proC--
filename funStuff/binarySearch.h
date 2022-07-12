#include <iostream> /// for IO operations
#include <vector>

int binarySearch(std::vector<int> arr, int val)
{
    int low = 0;               // set the lowest point of the vector.
    int high = arr.size() - 1; // set the highest point of the vector.

    while (low <= high)
    {
        int m = low + (high - low) / 2; // set the pivot point

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