#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
int MOD = 1e9+7;
long long helper(int i,int j, vector<string>& grid,vector<vector<ll>>& dp){
    int n = grid.size();
    int m = grid[0].size();
    if(i==n-1 && j==n-1){
        return true;
    }
    if(i>=n || j>=m) return false;
    long long cnt = 0;
    if(i+1<n && grid[i+1][j]!='*'){
        cnt+=helper(i+1,j,grid,dp)%MOD;
    }
    if(j+1<m && grid[i][j+1]!='*'){
        cnt+=helper(i,j+1,grid,dp)%MOD;
    }
    return cnt%MOD;
}
void solve(int n,int m,vector<string> grid)
{
    vector<vector<ll>> dp(n+1,vector<ll> (m+1,0));
    // cout<<helper(0,0,grid,dp);
    if(grid[0][0]=='*'){
        cout<<0;
        return;
    }
    dp[n-1][n-1] = grid[n-1][n-1]=='.';
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i==n-1 && j==n-1 ) continue;
            long long cnt = 0;
            if(i+1<n && grid[i+1][j]!='*'){
                cnt+=dp[i+1][j]%MOD;
            }
            if(j+1<m && grid[i][j+1]!='*'){
                cnt+=dp[i][j+1]%MOD;
            }
            dp[i][j]=cnt%MOD;
        }
    }
    cout<<dp[0][0];
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    vector<string> grid(T);
    for(int i=0;i<T;i++){
        cin>>grid[i];
    }
    solve(T,T,grid);
    return 0;
}