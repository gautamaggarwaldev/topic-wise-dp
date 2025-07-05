#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = wt.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1));

        // Intializing the dp array with zero as base condition in recursive solution
        // i.e. when n = 0 or W = 0, the maximum value
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < W + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
            }
        }

        // Filling the dp array using the bottom-up approach
        // i.e. iterating through all items and all capacities
        // here i ---> n (size of wt and val vector)
        // and j ---> W (capacity of knapsack)
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < W + 1; j++)
            {
                if (j >= wt[i - 1])
                {
                    dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][W];
    }
};
int main()
{
}