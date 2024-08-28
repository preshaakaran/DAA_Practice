#include<stdio.h>
#include<conio.h>
int min, max, arr[100];

void minmax(int i, int j){
	int min1, max1, mid;
	if (i==j){
		min = arr[i];
		max = arr[i];
	}
	else{
		if(i == j-1){
			if(arr[i] < arr[j]){
				min = arr[i];
				max = arr[j];
			}
			else{
				min = arr[j];
				max = arr[i];
			}
		}
		else{
			mid = (i + j )/2;
			minmax(i, mid);
			min1 = min;
			max1 = max;
			minmax(mid+ 1, j);
			if(min1 < min) min = min1;
			if(max1 > max) max = max1;
		}
	}

}
int main(){
	int i,n;
	clrscr();
	printf("Enter the length of the array: ");
	scanf("%d", &n);
	for(i = 0; i< n; i++){
		scanf("%d", &arr[i]);
	}
	max = arr[0];
	min = arr[0];
	minmax(0, n-1);
	printf("Min: %d\n Max: %d", min, max);
	getch();
	return 0;
}