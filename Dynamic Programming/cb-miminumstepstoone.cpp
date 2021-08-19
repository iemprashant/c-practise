// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:
	int minSteps(int n)
	{
		int dp[n + 1];
		dp[1] = 0;
		for (int i = 2; i <= n; i++) {
			int ans = dp[i- 1];
			if (i % 2 == 0) {
				ans = min(ans, dp[i / 2]);
			}
			if (i % 3 == 0) {
				ans = min(ans, dp[i / 3]);
			}
			dp[i] = ans+1;
		}
		return dp[n];
	}
};


int main()
{


	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;



		Solution ob;
		cout << ob.minSteps(n) << "\n";

	}
	return 0;
}

// } Driver Code Ends