#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long x,n;
    cin>>x>>n;
    set<long long> arr;
    arr.insert(0);
    arr.insert(x);
    multiset<long long> passLen;
    passLen.insert(x);
    long long ans =0;
    for(int i=0;i<n;i++){
        long long a;
        cin>>a;
        auto it1= arr.upper_bound(a);
        auto it2= it1;
        it2--;
        arr.insert(a);
        auto it = passLen.find(*it1-*it2);
        passLen.erase(it);
        passLen.insert(*it1-a);
        passLen.insert(a-*it2);
        ans=*passLen.rbegin();
        cout<<ans<<" ";
    }
    return 0;
}