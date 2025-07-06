#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int cutRodRec(vector<int> &price, vector<int> &len, int n, int W)
    {
        if (n == 0 || W == 0)
            return 0;
        if (W >= len[n - 1])
        {
            return max(price[n - 1] + cutRodRec(price, len, n, W - len[n - 1]), cutRodRec(price, len, n - 1, W));
        }
        else
            return cutRodRec(price, len, n - 1, W);
    }
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<int> len;
        for (int i = 1; i <= n; i++)
        {
            len.push_back(i);
        }
        int W = len.size();
        int ans = cutRodRec(price, len, n, W);
        return ans;
    }
};
int main()
{
}