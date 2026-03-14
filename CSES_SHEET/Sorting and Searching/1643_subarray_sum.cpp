#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    long long sum=0;
    long long ans=arr[0];
    for(int i=0;i<n;i++){
        sum+=arr[i];
        ans=max(sum,ans);
        if(sum<0) sum=0;
    }
    cout<<ans<<endl;
    return 0;
}