    #include<bits/stdc++.h>
    using namespace std;
    #define ull unsigned long long
    #define ll long long
    int MOD = 1e9+7;
    long long helper(int i,int j,int prev, vector<int> arr){
        int n = arr.size();
        if(i==n){
            return true;
        }
        ll cnt = 0;
        if(prev==-1){
            if(arr[i]!=0){
                cnt+=helper(i+1,j,arr[i],arr)%MOD;
            }else{
                for(int k=1;k<=j;k++){
                    cnt+=helper(i+1,j,k,arr)%MOD;
                }
            }
        }else{
            if(arr[i]!=0){
                if(abs(prev-arr[i])<=1){
                    cnt+=helper(i+1,j,arr[i],arr)%MOD;
                }else return false;
            }else{
                for(int k = prev-1;k<=prev+1;k++){
                    if(k>=1 && k<=j){
                        cnt+=helper(i+1,j,k,arr)%MOD;
                    }
                }
            }
        }
        return cnt;
    }
    void solve(int n,int m,vector<int> arr)
    {
        vector<vector<ll>> dp(n+1,vector<ll> (m+2,0));
        for(int i=0;i<=m+1;i++){
            dp[n][i] = 1;
        }
        // cout<<helper(0,m,-1,arr);
        
        for(int i=n-1;i>=0;i--){
            for(int prev=m;prev>=-1;prev--){
                ll cnt = 0;
                if(prev==-1){
                    if(arr[i]!=0){
                    cnt+=dp[i+1][arr[i]+1]%MOD;
                    }else{
                        for(int k=1;k<=m;k++){
                        cnt+=dp[i+1][k+1]%MOD;
                        }
                    }
                }else{
                    if(arr[i]!=0){
                        if(abs(prev-arr[i])<=1){
                            cnt+=dp[i+1][arr[i]+1]%MOD;
                        }else{
                            dp[i][prev+1] = 0;
                            continue;
                        }
                    }else{
                        for(int k = prev-1;k<=prev+1;k++){
                            if(k>=1 && k<=m){
                                cnt += dp[i+1][k+1] % MOD;
                            }
                        }
                    }
                }
            dp[i][prev+1]=cnt % MOD;
        }
        }
        cout<<dp[0][0] % MOD;
    }
    
    int main()
    {
        ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
        int n,m;
        cin>>n>>m;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            arr.push_back(a);
        }
        solve(n,m,arr);
        return 0;
    }