#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin>>n;
        string s0,s1;
        cin>>s0>>s1;
        vector<int> dp(n +1, INT_MAX);
        dp[0]=0;
        
        for (int i=0;i<n;i++) {
            if (dp[i] == INT_MAX) continue;
            int vert_cost = (s0[i] != s1[i]) ? 1 :0;
            dp[i + 1] = min(dp[i + 1], dp[i] + vert_cost);
            if (i+1<n) {
                int horiz_cost=(s0[i] != s0[i+1] ? 1: 0)
                               + (s1[i] != s1[i+1] ? 1 : 0);
                dp[i + 2] = min(dp[i + 2], dp[i] + horiz_cost);
            }
        }
        
        cout<<dp[n]<<endl;
    }
    
    return 0;
}