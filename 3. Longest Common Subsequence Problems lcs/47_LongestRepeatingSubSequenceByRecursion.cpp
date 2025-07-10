#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int lcs(string s, string t, int n, int m)
    {
        if (n == 0 || m == 0)
            return 0;
        if (s[n - 1] == t[m - 1] && n != m)
        {
            return 1 + lcs(s, t, n - 1, m - 1);
        }
        else
            return max(lcs(s, t, n - 1, m), lcs(s, t, n, m - 1));
    }
    int LongestRepeatingSubsequence(string &s)
    {
        string t = s;
        int n = s.length();
        int m = t.length();
        int ans = lcs(s, t, n, m);
        return ans;
    }
};
int main()
{
}