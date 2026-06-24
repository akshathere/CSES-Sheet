#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
int MOD = 1e9+7;
long long helper(int sum,vector<int>& arr,vector<long long>& dp){
    if(sum==0){
        return 1;
    }
    long long cnt =0;
    if(dp[sum]!=-1) return dp[sum];
    for(int i=0;i<=arr.size();i++){
        if(sum>=arr[i]){
            cnt+=helper(sum-arr[i],arr,dp) % MOD;
        }
    }
    return dp[sum]=cnt % MOD;
}
void solve(int sum,vector<int>& arr)
{
    vector<long long> dp(sum+1,0);
    dp[0]=1;
    for(int j=0;j<arr.size();j++){
        for(int i=1;i<=sum;i++){
            long long cnt=0;
            if(i>=arr[j]){
                dp[i] += dp[i-arr[j]];
            }
            if(dp[i] >= MOD){
                dp[i] -= MOD;
            }
        }
    }
    cout<<dp[sum];
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    int sum ;
    cin>>sum;
    vector<int> arr;
    for(int i=0;i<T;i++){
        int a ;
        cin>>a;
        arr.push_back(a);
    }
    solve(sum,arr);
    return 0;
}