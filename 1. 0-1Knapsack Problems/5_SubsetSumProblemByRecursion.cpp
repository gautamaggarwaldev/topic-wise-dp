#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool subsetSumRec(vector<int> &arr, int sum, int n)
    {
        if (sum == 0)
            return true;
        if (n == 0)
            return false;
        if (sum >= arr[n - 1])
        {
            return subsetSumRec(arr, sum - arr[n - 1], n - 1) || subsetSumRec(arr, sum, n - 1);
        }
        else
        {
            return subsetSumRec(arr, sum, n - 1);
        }
    }
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        bool ans = subsetSumRec(arr, sum, n);
        return ans;
    }
};
int main()
{
}