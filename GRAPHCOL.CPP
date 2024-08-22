#include <stdio.h>
#include <conio.h>

#define V 4 // Number of vertices

// Check if it's safe to color the vertex v with color c
int isSafe(int graph[V][V], int color[], int v, int c) {
    int i;
    for (i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c)
	    return 0;
    }
    return 1;
}

// Recursive function to solve graph coloring
int graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    int c;
    if (v == V)
	return 1;

    for (c = 1; c <= m; c++) {
        if (isSafe(graph, color, v, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
		return 1;
            color[v] = 0; // Backtrack
        }
    }
    return 0;
}

// Wrapper function to solve graph coloring
int graphColoring(int graph[V][V], int m) {
    int color[V],i;
    for (i = 0; i < V; i++)
        color[i] = 0;

    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist.\n");
	return 0;
    }

    printf("Solution exists: Assigned colors:\n");
    for (i = 0; i < V; i++)
	printf("Vertex %d: Color %d\n", i, color[i]);
    return 1;
}

int main() {
    int graph[V][V] = {
	{0, 1, 1, 1},
	{1, 0, 1, 0},
	{1, 1, 0, 1},
	{1, 0, 1, 0}
    };
    int m = 3; // Number of colors
    clrscr();

    graphColoring(graph, m);
    getch();
    return 0;
}
