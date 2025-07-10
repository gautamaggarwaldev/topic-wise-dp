#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int lcs(string s, string t, int n, int m)
    {
        if (n == 0 || m == 0)
            return 0;
        if (s[n - 1] == t[m - 1])
        {
            return 1 + lcs(s, t, n - 1, m - 1);
        }
        return max(lcs(s, t, n - 1, m), lcs(s, t, n, m - 1));
    }
    int longestPalindromeSubseq(string s)
    {
        string t = s;
        reverse(t.begin(), t.end()); // reverse the string s to get t
        // Now we need to find the length of the longest common subsequence between s and t
        int n = s.length();
        int m = t.length();
        int ans = lcs(s, t, n, m);
        return ans;
    }
};
int main()
{
}