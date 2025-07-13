#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int mcm(int k, int n)
    {
        if (n == 0 || n == 1)
            return n;
        if (k == 1)
            return n;
        int mn = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            // Drop the egg from the ith floor and check the worst case
            // If the egg breaks, we check the floors below (i - 1) with one less egg (k - 1).
            // If the egg doesn't break, we check the floors above (n - i) with the same number of eggs (k).
            // We take the maximum of these two cases because we want to ensure we find the worst case.
            int temp = 1 + max(mcm(k - 1, i - 1), mcm(k, n - i));
            mn = min(mn, temp);
        }
        return mn;
    }
    int superEggDrop(int k, int n)
    {
        // k --> no. of eggs
        // n --> no. of floors
        int ans = mcm(k, n);
        return ans;
    }
};
int main()
{
}