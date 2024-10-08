#include <stdio.h>
#include <string.h>
#include <conio.h>

int i, j, m, n, LCS_table[20][20];
char S1[20], S2[20];

void lcsAlgo() {
    m = strlen(S1);
    n = strlen(S2);

    // Filling 0's in the matrix
    for (i = 0; i <= m; i++)
        LCS_table[i][0] = 0;
    for (i = 0; i <= n; i++)
        LCS_table[0][i] = 0;

    // Creating the matrix in bottom-up way
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
            } else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1]) {
                LCS_table[i][j] = LCS_table[i - 1][j];
            } else {
                LCS_table[i][j] = LCS_table[i][j - 1];
            }
        }

    int index = LCS_table[m][n];
    char* lcsAlgo = new char[index + 1];
    lcsAlgo[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (S1[i - 1] == S2[j - 1]) {
            lcsAlgo[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        } else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
            i--;
        else
            j--;
    }

    // Printing the sub sequences
    printf("S1 : %s \nS2 : %s \n", S1, S2);
    printf("LCS: %s", lcsAlgo);
}

int main() {
    clrscr();
    printf("Enter string S1: ");
    scanf("%s", S1);
    printf("Enter string S2: ");
    scanf("%s", S2);
    lcsAlgo();
    printf("\n");
    getch();
    return 0;
}
