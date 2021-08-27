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
int noofwaystoclimbwithatmostksteps(int n,int k){
	int dp[n+1]={0};
	dp[0]=dp[1]=1;
	for(int i=2;i<=k;i++){
		dp[i]=2*dp[i-1];
	}
	for(int i=k+1;i<=n;i++){
		dp[i]=2*dp[i-1]-dp[i-k-1];
	}
	return dp[n];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		cout<<noofwaystoclimbwithatmostksteps(n,k)<<endl;
		
}
return 0;
}