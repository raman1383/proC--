#pragma once
#include <iostream>
#include <climits>
using std::cout, std::endl;

int miniDist(int distance[], bool Tset[])
{
    int minimum = INT_MAX, ind;
    for (int k = 0; k < 6; k++)
    {
        if (Tset[k] == false && distance[k] <= minimum)
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

    for (int k = 0; k < 6; k++)
    {
        int m = miniDist(distance, Tset);
        Tset[m] = true;
        for (int k = 0; k < 6; k++)
        {
            if (!Tset[k] && graph[m][k] && distance[m] != INT_MAX && distance[m] + graph[m][k] < distance[k])
                distance[k] = distance[m] + graph[m][k];
        }
    }
    cout << "Vertex\t\tDistance from source vertex" << endl;
    for (int k = 0; k < 6; k++)
    {
        char str = 65 + k;
        cout << str << "\t\t\t" << distance[k] << endl;
    }
}