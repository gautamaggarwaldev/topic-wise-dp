#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int coinnChangeMemo(vector<int> &coins, int amount, int n, vector<vector<int>> &dp)
    {
        // base condition
        if (amount == 0) return 1;
        if (n == 0) return 0;

        if (dp[n][amount] != -1) return dp[n][amount];

        if (amount >= coins[n - 1])
        {
            return dp[n][amount] = coinnChangeMemo(coins, amount - coins[n - 1], n, dp) + coinnChangeMemo(coins, amount, n - 1, dp);
        }
        else return dp[n][amount] = coinnChangeMemo(coins, amount, n - 1, dp);
    }
    
    int count(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int ans = coinnChangeMemo(coins, amount, n, dp);
        return ans;
    }
};
int main()
{
}