#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::
tree_order_statistics_node_update> ordered_set;

void solve(){
    int n,k;
    cin>>n>>k;
    // similar to set<int> but also has a function ,
    // find_by_order(pos) -> returns iterator to the element at 'pos' position (0-based)
    ordered_set nums;
    for(int i=1;i<=n;i++){
        nums.insert(i);
    }
    int pos= 0;
    while(!nums.empty()){
        pos= (pos+k)%nums.size();
        auto it=  nums.find_by_order(pos);
        cout<<*it<<" ";
        nums.erase(it);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}