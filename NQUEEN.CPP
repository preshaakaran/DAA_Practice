#include <stdio.h>
#include <conio.h>

#define N 4 // Define the size of the chessboard

// Function to print the solution
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j++) {
	    printf("%d ", board[i][j]);
	}
	printf("\n");
    }
}

// Function to check if a queen can be placed on board[row][col]
int isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
	if (board[row][i] == 1)
	    return 0;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
	if (board[i][j] == 1)
	    return 0;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
	if (board[i][j]==1)
	    return 0;

    return 1;
}

// Recursive function to solve N-Queens problem
int solveNQueensUtil(int board[N][N], int col) {
    // If all queens are placed, return true
    if (col >= N)
	return 1;

    // Consider this column and try placing this queen in all rows
    for (int i = 0; i < N; i++) {
	// Check if the queen can be placed on board[i][col]
	if (isSafe(board, i, col)) {
	    // Place this queen in board[i][col]
	    board[i][col] = 1;

	    // Recur to place rest of the queens
	    if (solveNQueensUtil(board, col + 1))
		return 1;

	    // If placing queen in board[i][col] doesn't lead to a solution, then remove queen from board[i][col]
	    board[i][col] = 0; // Backtrack
	}
    }

    // If the queen cannot be placed in any row in this column, then return false
    return 0;
}

// Function to solve N-Queens problem
int solveNQueens() {
    int board[N][N] = {{0}};

    if (!solveNQueensUtil(board, 0)) {
        printf("Solution does not exist");
	return 0;
    }

    printSolution(board);
    return 1;
}

// Main function
int main() {
    clrscr();
    solveNQueens();
    getch();
    return 0;
}
