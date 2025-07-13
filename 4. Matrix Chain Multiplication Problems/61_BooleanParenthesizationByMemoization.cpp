#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int mcm(string s, int i, int j, bool isTrue, vector<vector<vector<int>>> &dp)
    {
        if (i > j)
        {
            return 0;
        }
        if (i == j)
        {
            if (isTrue)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }
        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
        int ans = 0;
        for (int k = i + 1; k <= j - 1; k += 2)
        {
            int lt = mcm(s, i, k - 1, true, dp);
            int lf = mcm(s, i, k - 1, false, dp);
            int rt = mcm(s, k + 1, j, true, dp);
            int rf = mcm(s, k + 1, j, false, dp);
            // Depending on the operator at position k, calculate the number of ways
            // to parenthesize the expression such that it evaluates to true or false.
            // For '&', both sides must be true for the result to be true.
            // For '|', at least one side must be true for the result to be true.
            // For '^', one side must be true and the other must be false for the result to be true.
            // The opposite logic applies for when the result is false.
            // Update the answer based on the operator and the desired result.
            if (s[k] == '&')
            {
                if (isTrue == true)
                    ans = ans + (lt * rt);
                else
                    ans = ans + (lf * rt) + (lf * rf) + (lt * rf);
            }
            else if (s[k] == '|')
            {
                if (isTrue == true)
                    ans = ans + (lt * rt) + (lt * rf) + (lf * rt);
                else
                    ans = ans + (lf * rf);
            }
            else if (s[k] == '^')
            {
                if (isTrue == true)
                    ans = ans + (lf * rt) + (lt * rf);
                else
                    ans = ans + (lt * rt) + (lf * rf);
            }
        }
        return dp[i][j][isTrue] = ans;
    }
    int countWays(string &s)
    {
        int n = s.length();
        // dp[i][j][isTrue] represents the number of ways to parenthesize the expression
        // from index i to j such that the result is isTrue.
        // Initialize dp with -1 for all indices.
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        int ans = mcm(s, 0, n - 1, true, dp);
        return ans;
    }
};
int main()
{
}