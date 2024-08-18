#include<stdio.h>
#include<conio.h>
#include<limits.h>


int minDistance(int dist[],  int sptSet[],int n){
	int min = INT_MAX, min_index, v;
	for(v = 0; v<n;v++){
		if(sptSet[v] == -1 && dist[v]<=min){
			min = dist[v];
			min_index = v;
		}
	}
	return min_index;
}

void printSolution(int dist[], int parent[], int src, int n){
	int i,j;
	printf("Vertex \t Distance from source \t Path\n");
	for(i = 1; i< n;i++){
		printf("%d \t %d \t\t\t",i,dist[i]);
		j = i;
		printf("%d",j);
		while(parent[j] != src){
			printf("<-%d",parent[j]);
			j = parent[j];
		}
		if(parent[j] == src){
			printf("<-%d",parent[j]);
		}
		printf("\n");
	}
}

void dijkstra(int G[10][10], int n, int src){
	int dist[10], parent[10], i,j,sptSet[10],count,u,v;
	for(i = 0; i< n; i++){
		dist[i] = INT_MAX;
		parent[i] = -1;
		sptSet[i] = -1;
	}
	dist[0] = 0;

	for(count = 0; count < n - 1; count++){
	       u = minDistance(dist,sptSet,n);
	       sptSet[u] = 1;
	       for(v = 0; v<n; v++){
			if(sptSet[v] == -1 && G[u][v] && dist[u] != INT_MAX && dist[u] + G[u][v] < dist[v]){
				dist[v] = dist[u] + G[u][v];
				parent[v] = u;
			}
	       }
	}
	printSolution(dist, parent, src, n);
}
int main(){
	int i,j,n,G[10][10],src;
	clrscr();
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	for(i=0; i< n; i++){
		for(j=0; j<n;j++){
			scanf("%d",&G[i][j]);
		}
	}
	printf("Enter the starting node: ");
	scanf("%d", &src);

	dijkstra(G,n,src);
	getch();
	return 0;

}