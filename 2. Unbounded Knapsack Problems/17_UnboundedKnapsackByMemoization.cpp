#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int knapSackMemo(vector<int> &val, vector<int> &wt, int n, int W, vector<vector<int>> &dp)
    {
        if (n == 0 || W == 0)
            return 0;
        if (dp[n][W] != -1)
            return dp[n][W];
        if (W >= wt[n - 1])
        {
            dp[n][W] = max(val[n - 1] + knapSackMemo(val, wt, n, W - wt[n - 1], dp), knapSackMemo(val, wt, n - 1, W, dp));
        }
        else
            dp[n][W] = knapSackMemo(val, wt, n - 1, W, dp);
        return dp[n][W];
    }
    int knapSack(vector<int> &val, vector<int> &wt, int W)
    {
        int n = wt.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        int ans = knapSackMemo(val, wt, n, W, dp);
        return ans;
    }
};
int main()
{
}