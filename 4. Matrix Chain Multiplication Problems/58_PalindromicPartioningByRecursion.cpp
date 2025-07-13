#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int mcm(string &s, int i, int j)
    {
        if (i >= j || isPalindrome(s, i, j))
            return 0;

        int mn = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int temp = 1 + mcm(s, i, k) + mcm(s, k + 1, j);
            mn = min(mn, temp);
        }
        return mn;
    }

    int palPartition(string &s)
    {
        int n = s.length();
        return mcm(s, 0, n - 1);
    }
};

int main()
{
}