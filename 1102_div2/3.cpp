#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
 
void solve()
{
    ll n;
    cin>>n;
    vector<ll> h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }

    for(int i=0;i<n;i++){
        vector<ll> L(n,0),R(n,0);

        L[i] = 0;
        for(int k=0;k<n-1;k++){
            int curr = (i+k) %n;
            int next = (curr+1)%n;
            L[next] = max(L[curr],h[curr]);
        }
        R[i] =0;
        for(int k=0;k<n-1;k++){
            int curr = (i-k+n) %n;
            int prev = (curr-1+n)%n;
            R[prev] = max(R[curr],h[prev]);
        }
        long long total_water = 0;
        for(int k=0;k<n;k++){
            total_water+=min(L[k],R[k]);
        }
        cout<< total_water<<(i==n-1 ? "":" ");
    }
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}