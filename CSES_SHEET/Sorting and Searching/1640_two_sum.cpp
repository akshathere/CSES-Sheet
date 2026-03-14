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
    int sum;
    cin>>sum;
    vector<int> arr;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
        mp[a]=i;
    }
    for(int i=0;i<n;i++){
        int s=sum-arr[i];
        if(mp.find(s)!=mp.end()){
            if(mp[s]!=i){
                cout<<i+1<<" "<<mp[s]+1<<endl;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}