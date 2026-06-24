#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<int,int> mp;
    map<int,int> mpp;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int  a;
        cin>>a;
        arr.push_back(a);
    }
    int cnt=0;
    int ans=0;
    bool a=false;
    int j=0;
    for(int i=0;i<n;i++){
        if(mp.find(arr[i])!=mp.end()){
            j=max(mp[arr[i]]+1,j);
        }
        ans=max(ans,i-j+1);
        mp[arr[i]]=i;
    }
    cout<<ans<<endl;
    return 0;
}