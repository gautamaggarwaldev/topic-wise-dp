#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool subsetSum(vector<int> &nums, int sum)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        bool ans = subsetSumRec(nums, sum, n, dp);
        return ans;
    }
    bool subsetSumRec(vector<int> &nums, int sum, int n, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return true;
        if (n == 0)
            return false;
        if (dp[n][sum] != -1)
        {
            return dp[n][sum];
        }
        if (sum >= nums[n - 1])
        {
            return dp[n][sum] = subsetSumRec(nums, sum - nums[n - 1], n - 1, dp) || subsetSumRec(nums, sum, n - 1, dp);
        }
        else
            return dp[n][sum] = subsetSumRec(nums, sum, n - 1, dp);
    }
    bool canPartition(vector<int> &nums)
    {
        long long sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (sum % 2 != 0)
            return false;
        else
            return subsetSum(nums, sum / 2);
    }
};
int main()
{
}