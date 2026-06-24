
#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
 
void solve()
{
    int n;
    cin >> n;
    long long sum = 0;
    long long curr_min = 2e18; 
    for (int i = 1; i <= n; ++i) {
        long long a;
        cin>>a;
        sum += a;
        long long h = sum / i;
        curr_min = min(curr_min, h);
        cout<<curr_min<<(i==n? "" : " ");
    }
    cout << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}