#include <iostream>
#include "dijkstra.h"
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
	return 0;
}