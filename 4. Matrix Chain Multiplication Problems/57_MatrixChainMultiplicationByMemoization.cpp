#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int mcm(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int mn = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int tempAns = mcm(arr, i, k, dp) + mcm(arr, k + 1, j, dp) + (arr[i - 1] * arr[k] * arr[j]);

            if (tempAns < mn)
            {
                mn = tempAns;
            }
        }
        return dp[i][j] = mn;
    }
    int matrixMultiplication(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = mcm(arr, 1, n - 1, dp);
        return ans;
    }
};
int main()
{
}