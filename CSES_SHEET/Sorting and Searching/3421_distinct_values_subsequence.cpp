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
    int MOD = 1e9+7;
    cin>>n;
    map<long long,long long> mp;
    for(int i=0;i<n;i++){
        long long a;
        cin>>a;
        mp[a]++;
    }
    long long sum=1;
    for(auto it: mp){
        sum*=(it.second+1);
        sum%=MOD;
    }
    cout<<sum-1<<endl;
    return 0;
}