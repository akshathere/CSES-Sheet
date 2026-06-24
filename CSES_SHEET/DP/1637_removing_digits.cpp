#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
long long helper(int sum,vector<long long>& dp){
    cout<<sum<<endl;
    if(sum==0) return 0;
    long long steps = INT_MAX;
    int s = sum;
    while(s){
        if(s%10 == 0){
            s/=10;
            continue;
        }
        steps = min(steps , helper(sum-(s%10),dp)+1);
        s/=10;
    }
    return dp[sum] = steps;
}
void solve(int sum)
{
    vector<long long> dp(sum+1,0);
    // cout<<helper(sum,dp);
    dp[0]=0;
    for(int i=1;i<=sum;i++){
        int s= i;
        ll steps = INT_MAX;
        while(s){
            if(s%10 == 0){
            s/=10;
            continue;
            }
            steps = min(steps , dp[i-(s%10)]+1);
            s/=10;
        }
        dp[i] = steps;
    }
    cout<<dp[sum];
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    
    solve(T);
    return 0;
}