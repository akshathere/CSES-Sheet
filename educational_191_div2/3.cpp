#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
 
void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    vector<int> ss(n+1,0);

    for(int i=0;i<n;i++){
        ss[i+1]= ss[i]+(s[i]=='('? 1:0);
    }

    vector<int> rr(n+1,0);
    for(int i=n-1;i>=0;i--){
        rr[i]=rr[i+1]+(s[i]==')'?1:0);
    }

    int mincost= n+1;
    int minp = -1;
    for (int p = 0; p <=n; p++)
    {
        if(ss[p]+rr[p]<mincost){
            mincost = ss[p]+rr[p];
            minp=p;
        }
    }
    vector<int> targets;
    for(int i=0;i<minp;i++){
        if(s[i]=='('){
            targets.push_back(i);
        }
    }
    for(int i=minp;i<n;i++){
        if(s[i]==')'){
            targets.push_back(i);
        }
    }

    int del = min(k,(int)targets.size());
    string ans(n,'0');
    for(int i=0;i<del;i++){
        ans[targets[i]]= '1';
    }
    cout<<ans<<"\n";
}


 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}