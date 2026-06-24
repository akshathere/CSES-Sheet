    #include<bits/stdc++.h>
    using namespace std;
    #define ull unsigned long long
    #define ll long long
    int MOD = 1e9+7;
    // vector<vector<ll>> dp(1e6+1,vector<ll> (2,0));
    ll dp[1000000+1][2];
    void solve(int n)
    {
       dp[n][0]=1;
       dp[n][1]=1;
       for(int i=n-1;i>=0;i--){
            // horizontal open
            // 2 horizontal open 1 vertical open
            dp[i][0] = (2LL *dp[i+1][0] + dp[i+1][1])%MOD;
            // vertical 
            // 4 vertical 1 horizontal
            // close both close left close right open both
            dp[i][1] = (4LL *dp[i+1][1] + dp[i+1][0])%MOD;
       }
       cout<< (dp[1][0]+ dp[1][1])%MOD << '\n';
    }
    void precompute(){
       dp[1][0]=1;
       dp[1][1]=1;
       for(int i=2;i<1e6+1;i++){
            // horizontal open
            // 2 horizontal open 1 vertical open
            dp[i][0] = (2LL *dp[i-1][0] + dp[i-1][1])%MOD;
            // vertical 
            // 4 vertical 1 horizontal
            // close both close left close right open both
            dp[i][1] = (4LL *dp[i-1][1] + dp[i-1][0])%MOD;
       }
    } 
    int main()
    {
        ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
        int T;
        cin>>T;
        precompute();
        while(T--){
            int n;
            cin>>n;
            cout<<(dp[n][1] + dp[n][0]) % MOD<<endl;
        }
        return 0;
    }