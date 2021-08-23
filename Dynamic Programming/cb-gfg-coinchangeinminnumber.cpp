
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	long long minimumNumberOfCoins(int coins[], int numberOfCoins, int value)
	{
		long long dp[value + 1]={0};
		for (long long i = 1; i <= value; i++) {
			dp[i]=INT_MAX;
			for (int j = 0; j < numberOfCoins; j++) {
				if (i >=coins[j])
				{
					long long mincoin = dp[i - coins[j]] ;
					dp[i]=min(dp[i],mincoin+1);
				}
			}
		}
		return dp[value]==INT_MAX?-1:dp[value];
	}
};
int main() {
	int testcases;
	cin >> testcases;
	while (testcases--)
	{
		//taking value
		int value;
		cin >> value;

		//taking number of coins
		int numberOfCoins;
		cin >> numberOfCoins;
		int coins[numberOfCoins];
		for (int i = 0; i < numberOfCoins; i++)
			cin >> coins[i];
		Solution obj;
		//calling function minimumNumberOfCoins()
		int answer = obj.minimumNumberOfCoins(coins, numberOfCoins, value);

		//printing "Not Possible" if answer is -1
		//else printing answer
		if (answer == -1)
			cout << "Not Possible" << endl;
		else
			cout << answer << endl;

	}
	return 0;
}