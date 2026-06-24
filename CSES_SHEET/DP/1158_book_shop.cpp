#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
int MOD = 1e9+7;
long long helper(int i,int x,vector<int> prices,vector<int> pages,vector<vector<ll>>& dp){
    if(i>=prices.size()) return 0;
    if(x==0) return 0;
    if(dp[0][x]!=-1) return dp[0][x];
    ll ans = INT_MIN;
    ans = max(helper(i+1,x,prices,pages,dp),ans);

    if(x>=prices[i]){
        ans = max(helper(i+1,x-prices[i],prices,pages,dp)+pages[i],ans);
        cout<<ans<<endl;
    }
    return dp[0][x] = ans;
}
void solve(int n,int x,vector<int> prices,vector<int> pages)
{
    vector<ll> dp(x+1,0);
    // cout<<helper(0,x,prices,pages,dp);
    
    for(int i=0;i<n;i++){
        for(int j=x;j>=prices[i];j--){
            dp[j] = max(dp[j], dp[j-prices[i]] + pages[i]);
        }
    }
    cout<<dp[x];
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    int x;
    cin>>n;
    cin>>x;
    vector<int> prices;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        prices.push_back(a);
    }
    vector<int> pages;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        pages.push_back(a);
    }
    solve(n,x,prices,pages);
    return 0;
}