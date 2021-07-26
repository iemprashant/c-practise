// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

bool ratinamaze(vector<vector<int>> &blocked_matrix,int &ways,int i,int j,int n,int m){
    //first check block or not
    //if box is block but block is last one then i & j ==n and return true
    if(i>n || j>m){
        return false;
    }
    // if maze block
    // i j 
    if(blocked_matrix[i][j]==1){
        return false;
    }
    // when reach end point
    if(i==n && j==m){
    	ways++;
        return true;
    }
    // if out of maze
    bool rightsuccess=ratinamaze(blocked_matrix,ways,i,j+1,n,m);
    bool downsuccess=ratinamaze(blocked_matrix,ways,i+1,j,n,m);
    if(rightsuccess || downsuccess){
        return true;
    }
    return false;

}
class Solution {
public:
	int FindWays(int n, int m, vector<vector<int>>&blocked_cells){
	    int ways=0;
	    vector<vector<int>>blocked_matrix(n,vector<int>(m,0));
	    for(int i=0;i<blocked_cells.size();i++){
	    	blocked_matrix[blocked_cells[i][0]-1][blocked_cells[i][1]-1]=1;
	    }
        bool ans =ratinamaze(blocked_matrix,ways,0,0,n-1,m-1);
        return ways;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		};
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends