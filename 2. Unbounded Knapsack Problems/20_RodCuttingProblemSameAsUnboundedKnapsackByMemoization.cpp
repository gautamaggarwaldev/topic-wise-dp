#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int cutRodMemo(vector<int> &price, vector<int> &len, int n, int W, vector<vector<int>> &dp)
    {
        if (n == 0 || W == 0)
            return 0;
        if (dp[n][W] != -1)
        {
            return dp[n][W];
        }
        if (W >= len[n - 1])
        {
            dp[n][W] = max(price[n - 1] + cutRodMemo(price, len, n, W - len[n - 1], dp), cutRodMemo(price, len, n - 1, W, dp));
        }
        else
        {
            dp[n][W] = cutRodMemo(price, len, n - 1, W, dp);
        }
        return dp[n][W];
    }
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<int> len;
        for (int i = 1; i <= n; i++)
        {
            len.push_back(i);
        }
        int W = len.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        int ans = cutRodMemo(price, len, n, W, dp);
        return ans;
    }
};
int main()
{
}