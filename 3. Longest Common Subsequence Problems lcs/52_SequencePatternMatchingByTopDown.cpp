#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for(int i=0;i<n+1;i++) {
            for(int j=0;j<m+1;j++) {
                if(i==0 || j==0) dp[i][j] = 0;
            }
        }
        for(int i=1;i<n+1;i++) {
            for(int j=1;j<m+1;j++) {
                if(s[i-1]==p[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        if(dp[n][m] == n){
            return true;
        }
        else {
            return false;
        }
    }
};
int main()
{
    Solution sol;
    string s = "wertyuiodfghjnm";
    string p = "asdfghjklertyuasdfghjklertyuioxcvbnmwertyuiosdfghjkxcnmioxcvbnmwertyuiosdfghjkxcnm";
    if (sol.isMatch(s, p))
    {
        cout << "Pattern matches the sequence." << endl;
    }
    else
    {
        cout << "Pattern does not match the sequence." << endl;
    }
}