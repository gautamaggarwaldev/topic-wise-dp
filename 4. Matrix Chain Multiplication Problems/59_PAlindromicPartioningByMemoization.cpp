#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int mcm(string &s, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j || isPalindrome(s, i, j))
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mn = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int temp = 1 + mcm(s, i, k, dp) + mcm(s, k + 1, j, dp);
            mn = min(mn, temp);
        }
        return dp[i][j] = mn;
    }

    int palPartition(string &s)
    {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return mcm(s, 0, n - 1, dp);
    }
};

int main()
{
}