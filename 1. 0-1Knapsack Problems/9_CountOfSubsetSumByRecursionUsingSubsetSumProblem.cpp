#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int perfectSumRec(vector<int> &arr, int target, int n)
    {
        if (n == 0)
        {
            return (target == 0) ? 1 : 0;
        }
        if (target >= arr[n - 1])
        {
            return perfectSumRec(arr, target - arr[n - 1], n - 1) + perfectSumRec(arr, target, n - 1);
        }
        else
            return perfectSumRec(arr, target, n - 1);
    }
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        int ans = perfectSumRec(arr, target, n);
        return ans;
    }
};
int main()
{
}