
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canplace(vector <vector<int>> board, int n, int row, int col) {
        // check col
        for (int k = 0; k < row; k++) {
            if (board[k][col] == 1) {
                return false;
            }
        }
        // left diagonal
        int i = row;
        int j = col;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 1) {
                return false;
            }
            i--;
            j--;
        }
        // right digonal
        i = row;
        j = col;
        while (i >= 0 && j < n) {
            if (board[i][j] == 1) {
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    bool nqueensoln(int n, vector<vector<int>> board, vector<vector<int>> &ans, int row) {
        if (row == n) {
            for (int i = 0; i < n; i++)
            {
                vector<int>temp;
                for (int j = 0; j < n; j++)
                {
                    temp.push_back(board[i][j]);
                }
                ans.push_back(temp);
                
            }
            return true;
        }
        //rec case
        for (int col = 0; col < n; col++) {
            if (canplace(board, n, row, col)) {
                board[row][col] = 1;
                if (nqueensoln(n, board, ans, row + 1) == true) {
                    return true;
                }
                board[row][col] = 0;
            }
        }
        return false;
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board ( n , vector<int> (n, 0));
        vector<vector<int>> ans ;
        nqueensoln(n, board, ans, 0);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
}