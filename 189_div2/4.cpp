#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;

long long countMod(long long L,long long R,int rem){
    if(L>R) return 0;
    auto cnt=[&](long long x)->long long{
        if(x<rem) return 0;
        return (x-rem)/4+1;
    };
    return cnt(R)-cnt(L-1);
}

int main(){
    int t;cin>>t;
    while(t--){
        long long n,x;cin>>n>>x;
        long long aL=0,aR=x-1,bL=x,bR=n;

        long long c0L=countMod(aL,aR,3)+(aL==0?1:0);
        long long c0R=countMod(bL,bR,3);
        long long c1L=countMod(aL,aR,1);
        long long c1R=countMod(bL,bR,1);

        long long ans=(c0L%MOD)*(c0R%MOD)%MOD;
        ans=(ans+(c1L%MOD)*(c1R%MOD))%MOD;
        if((x-1)%4==2 && x%4==0) ans=(ans+1)%MOD;

        cout<<ans<<endl;
    }
}