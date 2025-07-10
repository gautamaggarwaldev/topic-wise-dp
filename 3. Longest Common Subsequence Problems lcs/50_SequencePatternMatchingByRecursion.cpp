#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int lcs(string s, string p, int n, int m)
    {
        if (n == 0 || m == 0)
            return false;
        if (s[n - 1] == p[m - 1])
        {
            return 1 + lcs(s, p, n - 1, m - 1);
        }
        else
            return max(lcs(s, p, n - 1, m), lcs(s, p, n, m - 1));
    }
    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();
        int ans = lcs(s, p, n, m);
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
    string s = "axy";
    string p = "adxcpy";
    if (sol.isMatch(s, p))
    {
        cout << "Pattern matches the sequence." << endl;
    }
    else
    {
        cout << "Pattern does not match the sequence." << endl;
    }
}