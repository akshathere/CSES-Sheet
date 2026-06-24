#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
 
void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]<mini){
            mini=arr[i];
            sum+=arr[i];
        }else{
            sum+=mini;
        }
    }
    cout<<sum<<"\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}