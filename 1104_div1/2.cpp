#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
bool isP(vector<ll> a, const vector<ll>& b) {
    sort(a.begin(), a.end());
    for (size_t i=0;i<a.size();i++) {
        if(a[i]>b[i]) {
            return false;
        }
    }
    return true;
}

ll find(vector<ll>& a, const vector<ll>& b) {
    ll ts=0;
    for (ll ct:b) {
        auto it=find_if(a.begin(),a.end(), 
                          [ct](ll ducks){return ducks<=ct;});
        int sc =distance(a.begin(), it);
        ts+=sc;
        a.erase(it);
    }
    return ts;
}
void solve() {
    int n;
    cin>>n;
    vector<ll>start_state(n);
    for (ll& val : start_state) {
        cin>>val;
    }
    vector<ll> end_state(n);
    for (ll& val:end_state) {
        cin>>val;
    }
    if (!isP(start_state, end_state)) {
        cout<<-1<<"\n";
        return;
    }
    ll ans=find(start_state, end_state);
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}