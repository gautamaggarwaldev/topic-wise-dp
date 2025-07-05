#include <iostream>
#include <vector>
using namespace std;
class Solution
{

public:
    int minDifference(vector<int> &arr)
    {

        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];

        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i < n + 1; i++)
            dp[i][0] = true;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        // The dp[n][j] will be true if there is a subset with sum j
        // We need to find the minimum difference between two subsets
        int mn = INT_MAX;
        for (int j = 0; j < sum + 1; j++)
        {
            if (dp[n][j] == true)
            {
                int s1 = j;
                int s2 = sum - s1;
                mn = min(mn, abs(s1 - s2));
            }
        }
        return mn;
    }
};

int main()
{
}