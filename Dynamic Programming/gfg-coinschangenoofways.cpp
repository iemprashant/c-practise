#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	long long numberOfWays(int coins[], int numberOfCoins, int value)
	{
		long long dp[value + 1] = {0};
		dp[0]=1;
		for (int coinindx = 0; coinindx < numberOfCoins; coinindx++) {
			for (int val = coins[coinindx]; val <= value; val++) {
				 dp[val]+=dp[val-coins[coinindx]];
			}
		}
		return dp[value];
	}
};

int main() {
	int testcases;
	cin >> testcases;
	while (testcases--)
	{
		int value;
		cin >> value;
		int numberOfCoins;
		cin >> numberOfCoins;
		int coins[numberOfCoins];
		for (int i = 0; i < numberOfCoins; i++)
			cin >> coins[i];
		Solution obj;
		cout << obj.numberOfWays(coins, numberOfCoins, value) << endl;

	}
	return 0;
}