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

int longestIncreasingSubsequenceMETHOD1(int arr[],int n){
	int dp[n]={1};//every one has minimum option of their length
	for(int i=0; i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i]){
				dp[i]=max(dp[j]+1,dp[i]);
			}
		}
	}
	return *max_element(dp, dp + n);;
}
int longestIncreasingSubsequenceMETHOD2(int arr[],int n){
	int dp[n+1];
	for(int i=1;i<=n;i++)
	{
		dp[i]=INT_MAX;
	}
	dp[0]=INT_MIN;
	for(int i=0; i<n;i++){
		for(int length=0;length<n;length++){
			if(dp[length]<arr[i] && arr[i]<dp[length+1]){
				dp[length+1]=arr[i];
			}
		}
	}
	int lis=0;
	for(int i=1;i<=n;i++)
	{
		if(dp[i]!=INT_MAX){
			lis=i;
		}
	}	
	return lis;
}
int longestSubsequenceMETHOD3(int n, int arr[])
    {
        if(n==1){
            return 1;
        }
        int dp[n + 1];
        dp[0] = INT_MIN;
        for (int i = 1; i <= n; i++) {
            dp[i] = INT_MAX;
        }
        for (int i = 0; i < n; i++) {
            int length = *upper_bound(dp, dp + n, arr[i]) - dp;
            if (dp[length - 1] < arr[i] && arr[i] < dp[length]) {
                dp[length] = arr[i];
            }
        }
        for(int i=n;i>=0;i--){
            if(dp[i]!=INT_MAX){
                return i;
            }
        }
        return 1;
    }
};
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<<longestIncreasingSubsequenceMETHOD2(arr,n)<<endl;
		
}
return 0;
}