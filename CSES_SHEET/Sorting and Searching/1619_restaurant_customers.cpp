#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    vector<int> dep;
    for(int i=0;i<n;i++){
        int a;
        int b;
        cin>>a>>b;
        arr.push_back(a);
        dep.push_back(b);
    }

    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int i=0;
    int j=0;
    int count=0;
    int ans=0;
    while(i<n && j<n){
        if(arr[i]<dep[j]){
            count++;
            ans=max(ans,count);
            i++;
        }else{
            count--;
            j++;
        }
    }
    cout<<ans<<endl;
    return 0;
}