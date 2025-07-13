#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool mcm(string s, string t)
    {
        if (s.compare(t) == 0)
            return true;
        if (s.length() <= 1)
            return false;
        int n = s.length();
        bool flag = false;
        for (int i = 1; i <= n - 1; i++)
        {   
            // Check if the first i characters of s can be scrambled to match the last i characters of t
            // and the remaining characters of s can be scrambled to match the first n-i characters of t.
            // Or, check if the first i characters of s can be scrambled to match the first i characters of t
            // and the remaining characters of s can be scrambled to match the last n-i characters of t.
            bool cond1 = mcm(s.substr(0, i), t.substr(n - i, i)) && mcm(s.substr(i, n - i), t.substr(0, n - i)); // gr | eat -----  eat | gr
            bool cond2 = mcm(s.substr(0, i), t.substr(0, i)) && mcm(s.substr(i, n - i), t.substr(i, n - i)); // gr | eat -----  gr | eat
            if (cond1 || cond2)
            {
                flag = true;
                break;
            }
        }
        return flag;
    }
    bool isScramble(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        if (n == 0 && m == 0)
            return false;
        if (n != m)
            return false;
        bool ans = mcm(s, t);
        return ans;
    }
};
int main()
{
}