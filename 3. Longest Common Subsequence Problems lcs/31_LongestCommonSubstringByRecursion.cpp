#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int lcs(string s1, string s2, int n, int m, int count)
    {
        if (n == 0 || m == 0) return count;

        int res = count;

        if (s1[n - 1] == s2[m - 1])
        {
            res = lcs(s1, s2, n - 1, m - 1, count + 1);
            return res;
        }

        int res1 = lcs(s1, s2, n - 1, m, 0);
        int res2 = lcs(s1, s2, n, m - 1, 0);

        return max({res, res1, res2});
    }

    int longestCommonSubstr(string &s1, string &s2)
    {
        int n = s1.length();
        int m = s2.length();
        int ans = lcs(s1, s2, n, m, 0);
        return ans;
    }
};
int main()
{
}