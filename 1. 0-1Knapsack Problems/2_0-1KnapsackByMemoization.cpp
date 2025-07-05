#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int knapsackRec(int W, vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &dp)
    {

        // base case
        if (n == 0 || W == 0)
            return 0;
        // if the value is already calculated, return it
        // This is the memoization step
        if (dp[n][W] != -1)
            return dp[n][W];
        // When we the weight of item is less than or equal to the knapsack capacity
        if (W >= wt[n - 1])
        {
            return dp[n][W] = max(val[n - 1] + knapsackRec(W - wt[n - 1], val, wt, n - 1, dp), knapsackRec(W, val, wt, n - 1, dp));
        }
        // the weight of item is greater than the knapsack capacity i.e. W
        else
            return dp[n][W] = knapsackRec(W, val, wt, n - 1, dp);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = wt.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        int ans = knapsackRec(W, val, wt, n, dp);
        return ans;
    }
};

int main()
{
}