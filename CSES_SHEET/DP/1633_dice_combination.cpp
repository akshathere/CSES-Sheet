#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
int MOD = 1e9+7;
long long helper(int sum,vector<long long>& dp){
    if(sum==0){
        return 1;
    }
    long long cnt =0;
    if(dp[sum]!=-1) return dp[sum];
    for(int i=1;i<=6;i++){
        if(sum>=i){
            cnt+=helper(sum-i,dp) % MOD;
        }
    }
    return dp[sum]=cnt % MOD;
}
void solve(int sum)
{
    vector<long long> dp(sum+1,-1);
    long long  a = helper(sum,dp) % MOD;
    cout<<a;
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    solve(T);
    return 0;
}