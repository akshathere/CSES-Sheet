#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
long long solve(int i,int n,int sum,vector<int>& arr,vector<vector<int>>& dp)
{
    if(i>=n) return 1e9;
    if(sum==0) return 0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    long long a = solve(i+1,n,sum,arr,dp);
    long long b = 1e9;
    if(arr[i]<=sum){
        b=solve(i,n,sum-arr[i],arr,dp)+1;
    }
    return dp[i][sum]=min(a,b);
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    int sum;
    cin>>sum;
    vector<int> arr; 
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    vector<vector<int>> dp (n+1,vector<int> (sum+1,0));
    int ans = 1e9;
    for(int i=0;i<sum+1;i++){
        dp[n][i]=1e9;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=sum;j++){
            long long a = dp[i+1][j];
            long long b = 1e9;
            if(arr[i]<=j){
                b=dp[i][j-arr[i]]+1;
            }
            dp[i][j]=min(a,b);
        }
    }
    ans = dp[0][sum];
    if(ans<1e9)
    cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}