#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1e9 + 7 ;
#define vi vector<int>
#define vs vector < string >
#define vll vector<ll>
#define vvi vector < vi >
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define REP(i,k,n) for (ll i = k; i <= n; ++i)
#define REPR(i,k,n) for (ll1i = k; i >= n; --i)
int maxproffromtreat( int prices[], int i, int j, int y, int dp[][100]) {
	//base case
	if (i > j) {
		return 0;
	}
	if(i==j) return prices[i]*y;
	if (dp[i][j] != 0) {
		return dp[i][j];
	}
	int op1 = prices[i] * y + maxproffromtreat(prices, i + 1, j, y + 1, dp);
	int op2 = prices[j] * y + maxproffromtreat(prices, i, j - 1, y + 1, dp);
	dp[i][j] = max(op1, op2);
	return dp[i][j];
}
int main() {
	int n;
	cin >> n;
	int prices[n];
	for (int i = 0; i < n; i++) {
		cin >> prices[i];
	}
	int dp[100][100] = {0};
	cout << maxproffromtreat(prices, 0, n - 1, 1,dp);
	return 0;
}