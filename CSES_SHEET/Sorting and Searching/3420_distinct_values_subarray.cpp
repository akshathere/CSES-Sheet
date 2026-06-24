#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long> arr;
    for(int i=0;i<n;i++){
        long long a;
        cin>>a;
        arr.push_back(a);
    }
    int i=0;
    int j=0;
    long long cnt=0;
    map<long long,long long> mp;
    while(i<n){
        while(mp.find(arr[i])!=mp.end()){   
            mp[arr[j]]--;
            if(mp[arr[j]]==0){
                mp.erase(arr[j]);
            }
            j++;
        }
        mp[arr[i]]++;
        cnt+=(i-j+1);
        i++;
    }
    cout<<cnt<<endl;
    return 0;
}