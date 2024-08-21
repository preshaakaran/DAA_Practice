#include<stdio.h>
#include<conio.h>

struct Item{
	int profit, weight;
};

void sort(struct Item arr[], int N){
	int i, j;
	struct Item temp;
	for (i = 0; i< N; i++){
		for(j = i+ 1; j< N; j++){
			if((float)arr[i].profit/arr[i].weight < (float)arr[j].profit/arr[j].weight){
			      temp = arr[i];
			      arr[i] = arr[j];
			      arr[j] = arr[i];
			}
		}
	}
}

double fractionalKnapsack(int W, struct Item arr[], int N){
	int i;
	sort(arr, N);

	double finalValue = 0.0;
	for(i = 0; i< N; i++){
		if(arr[i].weight <= W){
			W -= arr[i].weight;
			finalValue += arr[i].profit;
		}
		else{
			finalValue += arr[i].profit* ((double)W/(double)arr[i].weight);
			break;
		}
	}
	return finalValue;
}

int main(){
	 int W = 50, N, i ;
	 struct Item arr[50];
	 clrscr();
	 printf("Enter the length of the items: ");
	 scanf("%d", &N);
	 printf("Enter profit and the weight");
	 for (i = 0; i< N; i++){
		scanf("%d %d", &arr[i].profit, &arr[i].weight);
	 }
	 for(i = 0; i< N ; i++){
	 printf("Profit: %d and Weight = %d\n", arr[i].profit, arr[i].weight);
	 }

	 printf("Maximun profit is : %.2f", fractionalKnapsack(W, arr, N));
	getch();
	return 0;



}