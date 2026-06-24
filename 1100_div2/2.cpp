#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
 
void solve()
{
    int n;
    cin>>n;
    vector<int> a;
    vector<int>b;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        a.push_back(c);
    }
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        b.push_back(c);
    }
    long long ans=0;
    int maxi=0;
    for(int i=0;i<n;i++){
        if(a[i]>b[i]){
            ans+=a[i];
            maxi=max(maxi,b[i]);
        }else{
            ans+=b[i];
            maxi=max(maxi,a[i]);
        }
    }
    cout<<ans+maxi<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}