#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    unordered_map<string, int> mp;

    int mcm(string &s, int i, int j, bool isTrue)
    {
        if (i > j)
            return 0;

        if (i == j)
        {
            if (isTrue)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }
        // Create a unique key for the current state
        // The key is a combination of indices and the boolean value.
        string key = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
        if (mp.find(key) != mp.end())
            return mp[key];

        int ans = 0;

        for (int k = i + 1; k <= j - 1; k += 2)
        {
            int lt = mcm(s, i, k - 1, true);
            int lf = mcm(s, i, k - 1, false);
            int rt = mcm(s, k + 1, j, true);
            int rf = mcm(s, k + 1, j, false);

            if (s[k] == '&')
            {
                if (isTrue)
                    ans += lt * rt;
                else
                    ans += lf * rt + lt * rf + lf * rf;
            }
            else if (s[k] == '|')
            {
                if (isTrue)
                    ans += lt * rt + lt * rf + lf * rt;
                else
                    ans += lf * rf;
            }
            else if (s[k] == '^')
            {
                if (isTrue)
                    ans += lt * rf + lf * rt;
                else
                    ans += lt * rt + lf * rf;
            }
        }

        return mp[key] = ans;
    }

    int countWays(string &s)
    {
        mp.clear(); // Clear the map before starting a new computation
        return mcm(s, 0, s.size() - 1, true);
    }
};
int main()
{
}