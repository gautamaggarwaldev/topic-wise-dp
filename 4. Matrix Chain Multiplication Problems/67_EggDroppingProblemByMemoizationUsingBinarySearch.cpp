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
        int low = 1, high = n;
        int mn = INT_MAX;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            int left = mcm(k-1,mid-1,dp);
            int right = mcm(k,n-mid,dp);

            int temp = 1 + max(left, right);
            mn = min(mn, temp);

            if (left < right)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
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