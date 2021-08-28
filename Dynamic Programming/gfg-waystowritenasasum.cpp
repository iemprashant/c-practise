// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
    long long mod=(10^9 + 7);
    int countWays(int n)
    {
        int  dp[n + 1] = {0};
        dp[0] = 1;
        //i is the variable used to pick to use as sum
        //j is variable as number which is is made
        // pick a i and give to j as per condition
        //loop from 1->n-1 as number need to be represented as sum of minimum 2 or more integers
        for (int i = 1; i < n; i++) {
            for (int j = i; j <= n; j++) {
                dp[j]+=dp[j-i]; 
                dp[j]%=1000000007;
            }
        }
        return dp[n];
    }
};

// { Driver Code Starts.
// Driver program
int main()
{
    //taking number of testcases
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countWays(n) << endl;
    }
    return 0;
}  // } Driver Code Ends