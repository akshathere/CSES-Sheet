#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
 
void solve()
{
    int n,k;
    cin>>n>>k;
    string A,B;
    cin>>A>>B;

    ll xA= 0,xB=0,xC=0;
    for(int i=0;i<n;i++){
        if(A[i]=='1') xA++;
        if(B[i]=='1') xB++;
        if(A[i]!=B[i]) xC++;
    }

    ll vA = xA * (n-xA);
    ll vB = xB * (n-xB);
    ll vC = xC * (n-xC);

    ll cA,cB,cC;
    if(k%2==1) {
        cA= ((1LL<<k) +1)/3;
        cB = cA;
        cC= cA;
    }else{
        cA= ((1LL<<k) +2)/3;
        cB= cA;
        cC= ((1LL<<k) -1)/3;
    }
    ll ans = cA*vA + cB*vB + cC*vC;
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}