#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minCoins(vector<int> &coins, int sum)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = INT_MAX - 1;
                if (j == 0)
                    dp[i][j] = 0;
            }
        }

        // 2nd row initialization
        for (int j = 1; j < sum + 1; j++)
        {
            if (j % coins[0] == 0)
            {
                dp[1][j] = j / coins[0];
            }
            else
                dp[1][j] = INT_MAX - 1;
        }

        for (int i = 2; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (j >= coins[i - 1])
                {
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum] == INT_MAX - 1 ? -1 : dp[n][sum];
    }
};
int main()
{
}