#include "funStuff/dijkstra.h"
#include "funStuff/bellman_ford.h"
#include "funStuff/quickSort.h"

int main()
{
    int graph[6][6] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}};
    dijkstra(graph, 0);

    int size;
    std::cout << "\nEnter the number of elements : ";
    std::cin >> size;
    int *arr = new int[size];
    std::cout << "\nEnter the unsorted elements : ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << "\n";
        std::cin >> arr[i];
    }
    sorting::quickSort(arr, 0, size);
    std::cout << "Sorted array\n";
    sorting::show(arr, size);
    delete[] arr;
}