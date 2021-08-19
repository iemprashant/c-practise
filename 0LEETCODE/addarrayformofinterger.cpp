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

vector<int> addToArrayForm(vector<int>& num, int k) {
	int n = num.size();
	reverse(num.begin(), num.end());
	int carry = 0;
	int sum = 0;
	int i;
	for (i = 0; i < n; i++) {
		if (k) {
			sum = (num[i] + k % 10) + carry;
			carry = sum / 10;
			num[i] = sum % 10;
			k = k / 10;
		}
		else
			break;
	}
	while (k) {
		sum = k % 10 + carry;
		carry = sum / 10;
		num.push_back(sum%10);
		k = k / 10;
	}	
	while (i < n) {
		sum = num[i] + carry;
		num[i] = sum % 10;
		carry = sum / 10;
		i++;
	}
	if (carry) {
		num.push_back(carry);
	}
	reverse(num.begin(), num.end());
	return num;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int number;
		vector<int> num{7};
		vector<int> newnum = addToArrayForm(num, k);
		for (auto it = newnum.begin(); it != newnum.end(); it++) {
			cout << *it << " ";
		}

	}
	return 0;
}