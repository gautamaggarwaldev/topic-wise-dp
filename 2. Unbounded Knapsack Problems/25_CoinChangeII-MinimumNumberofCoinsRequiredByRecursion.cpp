#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minCoinsRec(vector<int> &coins, int sum, int n)
    {
        if (sum == 0)
            return 0;
        if (n == 0)
            return INT_MAX;

        int include = INT_MAX;

        if (sum >= coins[n - 1])
        {
            int res = minCoinsRec(coins, sum - coins[n - 1], n);
            if (res != INT_MAX)
                include = res + 1;
        }
        int exclude = minCoinsRec(coins, sum, n - 1);
        return min(include, exclude);
    }
    int minCoins(vector<int> &coins, int sum)
    {
        int n = coins.size();
        int ans = minCoinsRec(coins, sum, n);
        return ans == INT_MAX ? -1 : ans;
    }
};
int main()
{
}