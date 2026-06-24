#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
 
void solve()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        int left = 0;
        int right = 0;
        for(int j=0;j<n;j++){
            if(arr[i]<arr[j]){
                right++;
            }
            if(arr[i]>arr[j]){
                left++;
            }
            
        }
        int calls = max(left,right);
        ans = min(ans,calls);
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