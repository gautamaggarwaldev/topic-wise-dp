#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    unordered_map<string, bool> mp;
    bool mcm(string s, string t)
    {
        if (s.compare(t) == 0)
            return true;
        if (s.length() <= 1)
            return false;
        string key = s + " " + t;
        if (mp.find(key) != mp.end())
            return mp[key];
        int n = s.length();
        bool flag = false;
        for (int i = 1; i <= n - 1; i++)
        {
            bool cond1 = mcm(s.substr(0, i), t.substr(n - i, i)) && mcm(s.substr(i, n - i), t.substr(0, n - i));
            bool cond2 = mcm(s.substr(0, i), t.substr(0, i)) && mcm(s.substr(i, n - i), t.substr(i, n - i));
            if (cond1 || cond2)
            {
                flag = true;
                break;
            }
        }
        return mp[key] = flag;
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