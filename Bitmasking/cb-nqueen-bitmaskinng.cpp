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
#define REPR(i,k,n) for (ll i = k; i >= n; --i)
int ans = 0;
int n, done;
void solvenqueen(int rowmask, int ld, int rd) {
	if (rowmask == done) {
		ans++;
		return;
	}
	int safe = done &(~(rowmask | ld | rd));
	while (safe) {
		int p = safe & (-safe);
		safe=safe-p;
		solvenqueen(rowmask|p,(ld|p)<<1,(rd|p)>>1);
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		done = ((1 << n) - 1);
		solvenqueen(0, 0, 0);
		cout << ans << endl;

	}
	return 0;
}