// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9


// } Driver Code Ends

class Solution
{
public:
	//Function to print grids of the Sudoku.
	void printGrid (int grid[N][N])
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				cout << grid[i][j] << " ";
	}
	bool canplace(int grid[N][N], int i, int j, int n, int val) {
		for (int x = 0; x < n; x++)
		{
			if (grid[x][j] == val || grid[i][x] == val) {
				return false;
			}
			// traverse subarray
			int rx = sqrt(n);
			int sx = (i / rx) * rx;
			int sy = (j / rx) * rx;
			for (int y = sy; y < sy + rx; y++) {
				for (int x = sx; x < sx + rx; x++)
				{
					if (grid[x][y] == val) {
						return false;
					}
				}
			}
		}
		return true;
	}
	// utility function to solve sudoko
	bool Sudoko(int grid[N][N], int i, int j, int n) {
		//base case
		if (i == n) {
			return true;
		}
		if (j == n) {
			return Sudoko(grid, i + 1, 0, n);
		}
		//skip prefiledcells
		if (grid[i][j] != 0) {
			return Sudoko(grid, i, j + 1, n);
		}
		//recursive case
		for (int num = 1; num <= n; num++) {
			if (canplace(grid, i, j, n, num))
			{
				grid[i][j] = num;
				//next cell check
				if (Sudoko(grid, i, j + 1, n) == true) {
					return true;
				}
			}
		}
		// backtracking
		grid[i][j] = 0;
		return false;
	}
	//Function to find a solved Sudoku.
	bool SolveSudoku(int grid[N][N])
	{
		if (Sudoko(grid, 0, 0, 9) == true)
		{
			return true;
		}
		return false;
	}


};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		int grid[N][N];

		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				cin >> grid[i][j];

		Solution ob;

		if (ob.SolveSudoku(grid) == true)
			ob.printGrid(grid);
		else
			cout << "No solution exists";

		cout << endl;
	}

	return 0;
}  // } Driver Code Ends