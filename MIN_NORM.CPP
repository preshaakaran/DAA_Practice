#include<stdio.h>
#include<conio.h>

void minmax(int arr[], int n){
	int i,low = arr[0], high = arr[0];
	for (i=0; i< n; i++){
		if(low > arr[i]) low = arr[i];
		if(high < arr[i]) high = arr[i];
	}
	printf("Lowest = %d\n Highest = %d",low,high);
}

int main(){
	int arr[10], i, n;
	clrscr();
	printf("Enter the size of the array");
	scanf("%d",&n);
	for (i=0; i< n; i++){
		scanf("%d", &arr[i]);
	}
	minmax(arr, n);
	getch();
	return 0;
}