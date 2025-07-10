#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int longestCommonSubstr(string &s1, string &s2)
    {
        int n = s1.length();
        int m = s2.length();
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]); // IMP ----> Update the answer with the maximum length found because substring can be present anywhere
                }
                else
                    dp[i][j] = 0;
            }
        }
        return ans;
    }
};
int main()
{
}