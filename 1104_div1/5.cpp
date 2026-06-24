#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long

void solve()
{
    int n;
    cin >> n;
    
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    vector<int> ans = b;
    bool valid = true;
    vector<bool> src_vis(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (b[i] != -1 && !src_vis[i]) {
            int u = i, v = b[i];
            do {
                src_vis[u] = true;
                u = a[u];
                v = a[v];
                
                if (ans[u]!=-1 && ans[u]!=v) {
                    valid = false;
                    break;
                }
                ans[u] = v;
            } while(u!=i);
            if (!valid) break;
        }
    }

    if(!valid){
        cout<<"NO\n";
        return;
    }
    vector<bool> target_used(n + 1,false);
    for(int i=1;i<=n;++i) {
        if (ans[i]!=-1) {
            if(target_used[ans[i]]) {
                valid = false;
                break;
            }
            target_used[ans[i]] = true;
        }
    }
    if (!valid) {
        cout<<"NO\n";
        return;
    }
    // We use a min-heap (priority_queue) so the smallest available element is always on top
    vector<bool> target_vis(n + 1, false);
    map<int, priority_queue<int, vector<int>, greater<int>>> at;
    for (int i=1;i<=n;++i) {
        if (!target_vis[i] && !target_used[i]) {
            int curr = i;
            int len = 0;
            int min_val = i;
            do {
                target_vis[curr] = true;
                min_val = min(min_val, curr);
                len++;
                curr = a[curr];
            } while (curr != i);
            at[len].push(min_val);
        } else if(!target_vis[i]){
            int curr = i;
            do {
                target_vis[curr] = true;
                curr = a[curr];
            } while (curr != i);
        }
    }
    for (int i=1;i<=n;++i) {
        if (ans[i] == -1) {
            int curr = i;
            int len = 0;
            do {
                len++;
                curr = a[curr];
            } while (curr != i);
            if (at[len].empty()) {
                valid = false;
                break;
            }
            int v = at[len].top();
            at[len].pop();
            int u =i;
            do {
                ans[u]=v;
                u=a[u];
                v=a[v];
            } while(u!=i);
        }
    }

    if(!valid){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(int i=1;i<=n;++i){
        cout<<ans[i]<<(i==n?"":" ");
    }
    cout<<"\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}