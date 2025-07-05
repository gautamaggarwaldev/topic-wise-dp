#include <iostream>
#include <vector>
using namespace std;
class Solution
{

public:
    int minDifferenceRec(vector<int> &arr, int n, int sum, int currSum)
    {
        if (n == 0)
        {
            int s1 = currSum;
            int s2 = sum - currSum;
            return abs(s2 - s1);
        }

        int inc = minDifferenceRec(arr, n - 1, sum, currSum + arr[n - 1]);
        int exc = minDifferenceRec(arr, n - 1, sum, currSum);

        return min(inc, exc);
    }
    int minDifference(vector<int> &arr)
    {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        int ans = minDifferenceRec(arr, n, sum, 0);
        return ans;
    }
};

int main()
{
}