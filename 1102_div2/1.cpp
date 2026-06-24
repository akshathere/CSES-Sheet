#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
 
void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end(),greater<>());
    if(arr.size()<=2){
        cout<<arr[0]<<" "<<arr[1]<<"\n";
        return;
    }
    bool valid =true;
    for(int i=2;i<n;i++){
        if(arr[i]!=arr[i-2]%arr[i-1]){
            valid = false;
        }
    }
    if(!valid){
        cout<<-1<<"\n";
    }else{
        cout<<arr[0]<<" "<<arr[1]<<"\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}