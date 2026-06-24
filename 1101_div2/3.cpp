#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
 
void solve()
{
    int n;
    int x,s;

    cin>>n>>x>>s;
    string st;
    cin>>st;
    vector<int> dp(x+1,-1);
    dp[0]=0;

    for(int i=0;i<n;i++){
        vector<int> next_dp = dp;
        char c = st[i];

        for(int j=0;j<=x;j++){
            if(dp[j]==-1) continue;

            if((c=='I' || c=='A') && j<x){
                next_dp[j+1] = max(next_dp[j+1],dp[j]+1);
            }

            if( c=='E' || c=='A'){
                ll capacity = j*s;
                if(capacity - dp[j]>0){
                    next_dp[j] = max(next_dp[j],dp[j]+1);
                }
            }
        }
        dp = next_dp;
    }
    int ans = 0;
    for(int j=0;j<=x;j++){
        ans = max(ans, dp[j]);
    }
    cout<<ans<<'\n';
    
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}