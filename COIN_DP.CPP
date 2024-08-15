#include<stdio.h>
#include<conio.h>

int minimumOf(int a,int b){
	return (a<b)? a: b;
}
int min_coins_dp(int coins[], int n, int amount){
	int i,j,table[20];
	for(i = 1; i<=amount; i++){
		table[i] = 999;
	}
	table[0] = 0;

	for(i = 1; i<=amount; i++){
		for(j=0; j<n;j++){
			if(coins[j] <= i){
				table[i] = minimumOf(table[i], 1+table[i-coins[j]]);
			}
		}
	}
	if (table[amount] == 999){
	return -1;
	}
	else{
	return table[amount];
	}
}

int main(){
	int coins[] = {1,6,7,10};
	int n = sizeof(coins)/sizeof(coins[0]);
	int amount = 13;
	int min_coins = min_coins_dp(coins, n, amount);
	clrscr();
	if(min_coins != -1){
		printf("min coins needed %d",min_coins);
	}
	else{
		printf("Cannot make the denomination of %d",amount);
	}
	getch();
	return 0;
}