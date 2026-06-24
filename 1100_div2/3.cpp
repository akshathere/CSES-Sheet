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
    vector<int> ans;
    int count=0;
    for(int i=n-1;i>=0;i++){
        if(arr[i]<0){
            if(count%2==0){
                continue;
            }else{
                ans.push_back(i+1);
                count++;
            }
        }else{
            if(count%2==1){
                continue;
            }else{
                ans.push_back(i+1);
                count++;
            }
        }
    }
    cout<<count<<endl;
    for(size_t i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}