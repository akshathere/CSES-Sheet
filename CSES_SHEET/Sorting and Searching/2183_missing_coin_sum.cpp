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
    sort(arr.begin(),arr.end());
    if(arr[0]!=1){
        cout<<1<<endl;
        return 0;
    }
    long long L=1;
    for(int i=1;i<n;i++){
        if(arr[i]>L+1){
            cout<<L+1<<endl;
            return 0;
        }else{
            L+=arr[i];
        }
    }
    cout<<L+1<<endl;
    return 0;
}