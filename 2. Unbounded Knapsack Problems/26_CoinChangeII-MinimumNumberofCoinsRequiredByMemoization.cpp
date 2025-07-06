#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minCoinsMemo(vector<int> &coins, int sum, int n, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return 0;
        if (n == 0)
            return INT_MAX;

        if (dp[n][sum] != -1)
        {
            return dp[n][sum];
        }

        int include = INT_MAX;

        if (sum >= coins[n - 1])
        {
            int res = minCoinsMemo(coins, sum - coins[n - 1], n, dp);
            if (res != INT_MAX)
                include = res + 1;
        }
        int exclude = minCoinsMemo(coins, sum, n - 1, dp);
        return dp[n][sum] = min(include, exclude);
    }
    int minCoins(vector<int> &coins, int sum)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        int ans = minCoinsMemo(coins, sum, n, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};
int main()
{
}