#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int coinChangeRec(vector<int> &coins, int amount, int n)
    {
        // Base cases
        if (amount == 0)
            return 1;
        if (n == 0)
            return 0;
    
        if (amount >= coins[n - 1])
        {
            return coinChangeRec(coins, amount - coins[n - 1], n) + coinChangeRec(coins, amount, n - 1);
        }
        else
            return coinChangeRec(coins, amount, n - 1);
    }
    int count(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int ans = coinChangeRec(coins, amount, n);
        return ans;
    }
};
int main()
{
}