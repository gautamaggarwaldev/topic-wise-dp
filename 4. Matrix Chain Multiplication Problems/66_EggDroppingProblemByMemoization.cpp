#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int mcm(int k, int n, vector<vector<int>> &dp)
    {
        if (n == 0 || n == 1)
            return n;
        if (k == 1)
            return n;
        if (dp[k][n] != -1)
            return dp[k][n];
        int mn = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            int temp = 1 + max(mcm(k - 1, i - 1, dp), mcm(k, n - i, dp));
            mn = min(mn, temp);
        }
        return dp[k][n] = mn;
    }
    int superEggDrop(int k, int n)
    {
        // k --> no. of eggs
        // n --> no. of floors
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        int ans = mcm(k, n, dp);
        return ans;
    }
};
int main()
{
}