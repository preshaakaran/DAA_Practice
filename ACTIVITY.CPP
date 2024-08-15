#include<stdio.h>
#include<conio.h>

struct activity{
	int start, finish;
};

void sort(struct activity arr[], int n){
	int i , j;
	struct activity temp;
	for (i = 0; i< n; i++){
		for(j = i + 1; j < n; j++){
			if(arr[i].finish > arr[j].finish){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void activitySelection(struct activity arr[], int n){
	int i, j;
	sort(arr, n);

	i = 0 ;
	printf("The following activities are selected\n");
	printf("(%d, %d)\n",arr[i].start,arr[i].finish);

	for(j = 1; j < n; j++){
		if(arr[j].start >= arr[i].finish){
			printf("(%d, %d)\n",arr[j].start,arr[j].finish);
			i = j;
		}
	}

}


int main(){
	int i ,n;
	struct activity arr[10];
	clrscr();
	printf("Number of activities: ");
	scanf("%d", &n);
	printf("Enter Start and Finish time of the \n") ;
	for(i = 0; i< n; i++){
		printf("Activity %d: ", i+1);
		scanf("%d %d", &arr[i].start, &arr[i].finish);
		printf("\n");
	}
	activitySelection(arr, n);
	getch();
	return 0;

}