

#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int p;
    cin>>p;
    bool adj[7][7] = {};

    for(int i=1;i<=6;i++) {
        for(int j= 1;j<=6;j++) {
            if(i!=j && i+j != 7) {
                adj[i][j] =true;
            }
        }
    }
    while(p--){
        int n;
        cin>>n;

        vector<int> a(n+1);
        for(int i=1;i<=n;i++)
            cin>>a[i];
        const int INF = 1e9;

        vector<vector<int>> dp(n+1, vector<int>(7, INF));
        for(int face = 1; face <= 6; face++) {
            dp[1][face] = (a[1] != face);
        }

        for(int i = 2; i <= n; i++) {
            for(int cur = 1; cur <= 6; cur++) {
                for(int prev = 1; prev <= 6; prev++) {
                    if(adj[prev][cur]) {
                        dp[i][cur] = min(dp[i][cur],
                            dp[i-1][prev] + (a[i] != cur));
                    }
                }
            }
        }
        int ans =INF;
        for(int face = 1;face <= 6;face++)
            ans = min(ans,dp[n][face]);

        cout <<ans<<endl;
    }
      return 0;
}