#include <stdio.h>
#include <limits.h>
#include <conio.h>
#define MAX_WAREHOUSES 100
// Initialize the distance matrix
void initializeDist(int dist[MAX_WAREHOUSES][MAX_WAREHOUSES], int n)
{
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else
            {
                dist[i][j] = INT_MAX;
            }
        }
    }
}
void floydWarshall(int dist[MAX_WAREHOUSES][MAX_WAREHOUSES], int n)
{
    int k, i, j;
    for (k = 0; k < n; ++k)
    {
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                {
                    dist[i][j] = (dist[i][j] < dist[i][k] + dist[k][j]) ? dist[i][j] : dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
int main()
{
    int n, i, j; // Number of warehouses
    clrscr();
    printf("Enter the totl number of warehouses");
    scanf("%d", &n);
    int dist[MAX_WAREHOUSES][MAX_WAREHOUSES];
    initializeDist(dist, n);
    // Read the graph edges and weights (travel times)
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            scanf("%d", &dist[i][j]);
        }
    }
    // Run Floyd-Warshall algorithm
    floydWarshall(dist, n);
    // Print the resulting distance matrix
    printf("Shortest travel times between all pairs of warehouses:\n");
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (dist[i][j] == INT_MAX)
            {
                printf("INF ");
            }
            else
            {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
    getch();
    return 0;
}