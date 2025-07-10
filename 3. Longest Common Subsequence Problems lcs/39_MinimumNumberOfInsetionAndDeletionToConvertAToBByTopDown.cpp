#include <iostream>
#include <vector>
using namespace std;
// In this question we first convert string a into lcs and then convert lcs into string b.
// The number of insertions and deletions required to convert a to b is given by:
// (length of a + length of b - 2 * length of lcs)
class Solution
{
public:
    int minDistance(string s, string t)
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
        return n + m - (2 * dp[n][m]);
    }
};
int main()
{
}