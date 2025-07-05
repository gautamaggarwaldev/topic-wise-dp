#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int subsetSum(vector<int> &nums, int sum, int n, vector<vector<int>> &dp)
    {
        if (n == 0)
        {
            if (sum == 0)
                return 1;
            else
                return 0;
        }
        if (dp[n][sum] != -1)
        {
            return dp[n][sum];
        }
        if (sum >= nums[n - 1])
        {
            dp[n][sum] = subsetSum(nums, sum - nums[n - 1], n - 1, dp) + subsetSum(nums, sum, n - 1, dp);
        }
        else
        {
            dp[n][sum] = subsetSum(nums, sum, n - 1, dp);
        }
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int Tsum = 0;
        for (int i = 0; i < n; i++)
        {
            Tsum += nums[i];
        }
        if ((Tsum + target) % 2 != 0 || Tsum < abs(target))  // IMP check if the target is achievable
        {
            return 0; 
        }
        int sum = (Tsum + target) / 2;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        int ans = subsetSum(nums, sum, n, dp);
        return ans;
    }
};
int main()
{
}