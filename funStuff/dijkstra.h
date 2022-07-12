#pragma once
#include <iostream>
#include <climits>
using std::cout, std::endl;

int miniDist(const int distance[], const bool Tset[])
{
    int minimum = INT_MAX, ind;
    for (int k = 0; k < 6; k++)
    {
        if (!Tset[k] && distance[k] <= minimum)
        {
            minimum = distance[k];
            ind = k;
        }
    }
    return ind;
}

void dijkstra(int graph[6][6], int src)
{
    int distance[6];
    bool Tset[6];

    for (int k = 0; k < 6; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;
    }

    distance[src] = 0;

    for (int i = 0; i < 6; i++)
    {
        int m = miniDist(distance, Tset);
        Tset[m] = true;
        for (int j = 0; j < 6; j++)
        {
            if (!Tset[j] && graph[m][j] && distance[m] != INT_MAX && distance[m] + graph[m][j] < distance[j])
                distance[j] = distance[m] + graph[m][j];
        }
    }
    cout << "Vertex\t\tDistance from source vertex" << endl;
    for (int k = 0; k < 6; k++)
    {
        char str = 65 + k;
        cout << str << "\t\t\t" << distance[k] << endl;
    }
}

/*
    int graph[6][6] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}};
    dijkstra(graph, 0);
*/