#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int knapsackRec(int W, vector<int> &val, vector<int> &wt, int n)
    {
        // base case
        if (n == 0 || W == 0)
            return 0;
        // When we the weight of item is less than or equal to the knapsack capacity
        if (W >= wt[n - 1])
        {
            return max(val[n - 1] + knapsackRec(W - wt[n - 1], val, wt, n - 1), knapsackRec(W, val, wt, n - 1));
        }
        // the weight of item is greater than the knapsack capacity i.e. W
        else
            return knapsackRec(W, val, wt, n - 1);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = wt.size();
        int ans = knapsackRec(W, val, wt, n);
        return ans;
    }
};
int main()
{
}