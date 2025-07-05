#include <iostream>
#include <vector>
using namespace std;
class Solution
{

public:
    int minDifferenceRec(vector<int> &arr, int n, int sum, int currSum, vector<vector<int>> &dp)
    {
        if (n == 0)
        {
            int s1 = currSum;
            int s2 = sum - currSum;
            return abs(s2 - s1);
        }

        if (dp[n][currSum] != -1)
        {
            return dp[n][currSum];
        }

        int inc = minDifferenceRec(arr, n - 1, sum, currSum + arr[n - 1], dp);
        int exc = minDifferenceRec(arr, n - 1, sum, currSum, dp);

        return dp[n][currSum] = min(inc, exc);
    }
    int minDifference(vector<int> &arr)
    {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        int ans = minDifferenceRec(arr, n, sum, 0, dp);
        return ans;
    }
};

int main()
{
}