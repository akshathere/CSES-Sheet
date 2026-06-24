#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
 
void solve()
{
    float n,x,y,z;
    cin>>n>>x>>y>>z;
    int s = n - x*z;
    if(s<=0){
      int a=  ceil(n/(x+y));
      cout<<a<<"\n";
    }else{
        int a = ceil(n/(x+y));
        int b = z+ ceil((n-x*z)/(x+10*y));
        // cout<<b<<endl;
        a = min(a,b);
        cout<<a<<"\n";
    }
    
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}