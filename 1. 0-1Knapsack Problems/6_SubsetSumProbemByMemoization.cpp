#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool subsetSumMemo(vector<int> &arr, int sum, int n, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return true;
        if (n == 0)
            return false;
        if (dp[n][sum] != -1)
        {
            return dp[n][sum];
        }
        if (sum >= arr[n - 1])
        {
            return dp[n][sum] = subsetSumMemo(arr, sum - arr[n - 1], n - 1, dp) || subsetSumMemo(arr, sum, n - 1, dp);
        }
        else
            return dp[n][sum] = subsetSumMemo(arr, sum, n - 1, dp);
    }
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        bool ans = subsetSumMemo(arr, sum, n, dp);
        return ans;
    }
};
int main()
{
}