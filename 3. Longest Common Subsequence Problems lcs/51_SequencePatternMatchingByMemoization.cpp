#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int lcs(string s, string p, int n, int m, vector<vector<int>> &dp)
    {
        if (n == 0 || m == 0)
            return false;

        if (dp[n][m] != -1)
        {
            return dp[n][m];
        }
        if (s[n - 1] == p[m - 1])
        {
            return dp[n][m] = 1 + lcs(s, p, n - 1, m - 1, dp);
        }
        else
            return dp[n][m] = max(lcs(s, p, n - 1, m, dp), lcs(s, p, n, m - 1, dp));
    }
    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = lcs(s, p, n, m, dp);
        if (ans == n)
        {
            return true;
        }
        else
            return false;
    }
};
int main()
{
    Solution sol;
    string s = "wertyuiodfghjnm";
    string p = "asdfghjklertyuioxcvbnmwertyuiosdfghjkxcnm";
    if (sol.isMatch(s, p))
    {
        cout << "Pattern matches the sequence." << endl;
    }
    else
    {
        cout << "Pattern does not match the sequence." << endl;
    }
}