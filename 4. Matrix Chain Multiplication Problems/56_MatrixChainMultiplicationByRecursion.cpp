#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int mcm(vector<int> &arr, int i, int j)
    {
        if (i >= j)
        {
            return 0;
        }
        int mn = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            // arr[i-1] * arr[k] * arr[j] is the cost of multiplying the two matrices
            // formed by the indices i to k and k+1 to j
            // mcm(arr, i, k) is the cost of multiplying the first matrix
            // mcm(arr, k + 1, j) is the cost of multiplying the second matrix
            // The total cost is the sum of these two costs plus the cost of multiplying the two resulting matrices
            // together.
            int tempAns = mcm(arr, i, k) + mcm(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);

            if (tempAns < mn)
            {
                mn = tempAns;
            }
        }
        return mn;
    }
    int matrixMultiplication(vector<int> &arr)
    {
        int n = arr.size();
        int ans = mcm(arr, 1, n - 1);
        return ans;
    }
};
int main()
{
}