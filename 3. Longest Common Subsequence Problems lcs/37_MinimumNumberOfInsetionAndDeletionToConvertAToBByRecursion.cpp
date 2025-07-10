#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int lcs(string s, string t, int n, int m)
    {
        if (n == 0 || m == 0)
        {
            return 0;
        }
        if (s[n - 1] == t[m - 1])
        {
            return 1 + lcs(s, t, n - 1, m - 1);
        }
        else
            return max(lcs(s, t, n - 1, m), lcs(s, t, n, m - 1));
    }
    int minDistance(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        int x = lcs(s, t, n, m);
        int ans = n + m - (2 * x);
        return ans;
    }
};
int main()
{
}