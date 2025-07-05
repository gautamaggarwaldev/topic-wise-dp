#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int perfectSumMemo(vector<int> &arr, int target, int n, vector<vector<int>> &dp)
    {
        if (n == 0)
        {
            return (target == 0) ? 1 : 0;
        }
        if (dp[n][target] != -1)
        {
            return dp[n][target];
        }
        if (target >= arr[n - 1])
        {
            return dp[n][target] = perfectSumMemo(arr, target - arr[n - 1], n - 1, dp) + perfectSumMemo(arr, target, n - 1, dp);
        }
        else
            return dp[n][target] = perfectSumMemo(arr, target, n - 1, dp);
    }
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        int ans = perfectSumMemo(arr, target, n, dp);
        return ans;
    }
};
int main()
{
}