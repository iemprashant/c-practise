// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

bool ratinamaze(vector<vector<int>> &m,vector <string> &allpath ,string path,int i,int j,int n){
    //first check block or not
    //if box is block but block is last one then i & j ==n and return true
    if(i>n || j>n || i<0||j<0){
        return false;
    }
    // if maze block
    if(m[i][j]==0){
        return false;
    }
    // when reach end point
    if(i==n && j==n){
        allpath.push_back(path);
        return true;
    }
    // if out of maze
    m[i][j]=0;
    bool rightsuccess=ratinamaze(m,allpath,path+"R",i,j+1,n);
    bool leftsuccess=ratinamaze(m,allpath,path+"L",i,j-1,n);
    bool downsuccess=ratinamaze(m,allpath,path+"D",i+1,j,n);
    bool upsuccess=ratinamaze(m,allpath,path+"U",i-1,j,n);
    m[i][j]=1;
    if(rightsuccess || downsuccess || upsuccess || leftsuccess){
        return true;
    }
    return false;

}
class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector <string> allpath;
        ratinamaze(m,allpath,"",0,0,n-1);
        sort(allpath.begin(), allpath.end());
        return allpath;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends