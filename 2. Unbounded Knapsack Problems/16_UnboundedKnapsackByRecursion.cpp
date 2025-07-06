# include <iostream>
# include <vector>
using namespace std;
class Solution {
  public:
    int knapsackRec(vector<int>& val, vector<int>& wt, int n, int W) {
        if(n==0 || W==0) return 0;
        if(W>=wt[n-1]) {
            return max(val[n - 1]+knapsackRec(val,wt,n,W-wt[n-1]), knapsackRec(val,wt,n-1,W));
        }
        else return knapsackRec(val,wt,n-1,W);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int W) {
        int n = wt.size();
        int ans = knapsackRec(val,wt,n,W);
        return ans;
        
    }
};
int main() {
   
}