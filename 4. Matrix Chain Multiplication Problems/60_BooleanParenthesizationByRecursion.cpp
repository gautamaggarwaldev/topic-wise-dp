#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int mcm(string s, int i, int j, bool isTrue)
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
        int ans = 0;
        for (int k = i + 1; k <= j - 1; k += 2)
        {
            int lt = mcm(s, i, k - 1, true);
            int lf = mcm(s, i, k - 1, false);
            int rt = mcm(s, k + 1, j, true);
            int rf = mcm(s, k + 1, j, false);

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
        return ans;
    }
    int countWays(string &s)
    {
        int n = s.length();
        int ans = mcm(s, 0, n - 1, true);
        return ans;
    }
};
int main()
{
}