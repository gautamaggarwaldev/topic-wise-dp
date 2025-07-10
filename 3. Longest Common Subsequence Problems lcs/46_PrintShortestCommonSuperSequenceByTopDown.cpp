#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string shortestCommonSupersequence(string s, string t)
    {
        int n = s.length();
        int m = t.length();
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
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int i = n, j = m;
        string ans = "";
        while (i > 0 && j > 0)
        {
            if (s[i - 1] == t[j - 1])
            {
                ans += s[i - 1];
                i--;
                j--;
            }
            else
            {
                // If characters are not equal, we need to take the character from the string which has the larger LCS value
                // This ensures that we are building the shortest common supersequence
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    ans += s[i - 1];
                    i--;
                }
                else
                {
                    ans += t[j - 1];
                    j--;
                }
            }
        }
        // If there are remaining characters in either string, we add them to the result
        while (i > 0)
        {
            ans += s[i - 1];
            i--;
        }
        while (j > 0)
        {
            ans += t[j - 1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
}