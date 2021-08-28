#include<bits/stdc++.h>
using namespace std;
long long arr[1000];
long long dp[100][100];
long long csum(int s,int e){
	long long sum=0;
	for(int i=s;i<=e;i++){
		sum+=arr[i];
		sum%=100;
	}
	return sum;
}
long long solveMixtures(int i,int j){
	if(i>=j){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	dp[i][j]=INT_MAX;
	for(int k=i;k<=j;k++){
		long long smoke=solveMixtures(i,k)+solveMixtures(k+1,j)+csum(i,k)*csum(k+1,j);
		dp[i][j]=min(dp[i][j],smoke);
	}
	return dp[i][j];
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		
		memset(dp, -1, sizeof(dp));
		cout<<solveMixtures(0,n-1)<<endl;
	}
	return 0;
}