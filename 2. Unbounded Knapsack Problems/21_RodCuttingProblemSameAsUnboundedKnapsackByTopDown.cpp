#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<int> len;
        for (int i = 1; i <= n; i++)
        {
            len.push_back(i);
        }
        int W = len.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1));

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < W + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < W + 1; j++)
            {
                if (j >= len[i - 1])
                {
                    dp[i][j] = max(price[i - 1] + dp[i][j - len[i - 1]], dp[i - 1][j]);
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][W];
    }
};
int main()
{
}