#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int subsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++) // IMP We start j from 0 because sum 0 is valid (via empty subset) and needed for correct DP transitions.
            {
                if (j >= arr[i - 1])
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][sum];
    }
    int countPartitions(vector<int> &arr, int d)
    {
        int n = arr.size();
        int totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            totalSum += arr[i];
        }
        if ((totalSum + d) % 2 != 0)
            return 0;
        int sum = (totalSum + d) / 2; // Different line from subSetSum(arr,target)
        int ans = subsetSum(arr, sum);
        return ans;
    }
};
int main()
{
}