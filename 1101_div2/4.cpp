#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
 
void solve()
{
    int n;
    int x,s;
    int ans = 0;
    int tables = 0;
    long long seats = 0;
    int aActingAsE = 0;
    cin>>n>>x>>s;
    string st;
    cin>>st;
    
    for(char c :st){
        if(c=='I'){
            if(tables<x){
                tables++;
                seats+=(s-1);
                ans++;
            }
        }
        else if(c=='E'){
            if(seats>0){
                seats--;
                ans++;
            }else if(aActingAsE>0 && tables<x){
                aActingAsE--;
                tables++;
                seats+=(s-1);
                ans++;
            }
        }else if(c=='A'){
            if(seats>0){
                seats--;
                aActingAsE++;
                ans++;
            }else if(tables<x){
                tables++;
                seats+=(s-1);
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
    
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}