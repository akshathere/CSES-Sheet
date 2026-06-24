#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
 
void solve()
{
    int n;
    cin>>n;
    vector<int> arr;
    int maxi=0;
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
        maxi=max(maxi,a);
        mini=min(mini,a);
    }
    int avg = (maxi+mini)/2;
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(abs(arr[i]-avg),ans);
    }
    cout<<ans<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}