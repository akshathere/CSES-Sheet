#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
 
void solve()
{
    int n;
    cin>>n;
    vector<int> arr;
    if(n==2){   
        arr={1,2,1 ,2,2,1,1, 2};
    }else{
        for(int i=1;i<=n;i++){
            arr.push_back(i);
            arr.push_back(i);
        }
        for(int i=1;i<=n-2;i++){
            arr.push_back(i);
        }
        arr.push_back(n);
        arr.push_back(n-1);
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
    }
    for(int i=0;i<4*n;i++){
        cout<<arr[i]<<" ";
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