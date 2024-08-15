#include<stdio.h>
#include<conio.h>


int min_coins_greedy(int coins[], int n, int amount){
	int i,j,num_coins=0,temp,coins_list[20],pos=0;

	for(i = 0; i< n-1; i++){
		for(j = 0;j<n-i-1;j++){
			if(coins[j] < coins[j+1]){
				temp = coins[j];
				coins[j] = coins[j+1];
				coins[j+1] = temp;

			}
		}
	}
	for(i=0; i<n && amount>=0 ; i++){
		while(amount >= coins[i]){
			amount -= coins[i];
			num_coins++;
			coins_list[pos++]=coins[i];

		}
	}

	if(amount == 0){
		printf("Coins are: ");
		for(i=0;i<num_coins;i++){
			printf("%d ",coins_list[i]);
		}
		printf("\n");
		return num_coins;
	}
	return -1;
}

int main(){
	int coins[] = {1,6,7,10};
	int n = sizeof(coins)/sizeof(coins[0]);
	int amount = 13;
	clrscr();

	int min_coins_needed = min_coins_greedy(coins, n, amount);
	if(min_coins_needed != -1){
		printf("coins needed: %d",min_coins_needed);
	}
	else{
		printf("Cannot make the change of %d",amount);
	}
	getch();
	return 0;
}