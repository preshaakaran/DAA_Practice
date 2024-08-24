#include <stdio.h>
#define MAX_ITEMS 100

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n, int selected[])
{
    int include, exclude;
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1, selected);

    include = val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1, selected);
    exclude = knapSack(W, wt, val, n - 1, selected);

    if (include > exclude)
        selected[n - 1] = 1;
    else
        selected[n - 1] = 0;

    return max(include, exclude);
}

void printItems(int selected[], int n)
{
    int i;
    printf("Selected items: ");
    for (i = 0; i < n; i++)
    {
        if (selected[i])
            printf("%d ", i + 1);
    }
    printf("\n");
}

int main()
{
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    int selected[MAX_ITEMS];
    int maxProfit = knapSack(W, weight, profit, n, selected);
    clrscr();
    printItems(selected, n);
    printf("Maximum profit: %d\n", maxProfit);
    getch();
    return 0;
}