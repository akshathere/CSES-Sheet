#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
 
void solve()
{
    int n;
    cin>>n;
    vector<long long> arr(n+1,0);
    long long total=0;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        arr[i]=a;
    }
    vector<long long> prefSum(n+1,0);
    vector<long long> prefAbs(n+1,0);
    for(int i=1;i<=n;i++){
        prefAbs[i] = prefAbs[i-1]+abs(arr[i]);
        prefSum[i] = prefSum[i-1]+arr[i];
    }
    long long best = total;
    int last = -1;
    for(int i=1;i<=n;i++){
        if(arr[i]>0){
            long long suf= total-prefSum[i];
            long long candidate = prefAbs[i-1] - abs(arr[i]) +suf;
            if(candidate>best){
                best = candidate;
                last = i;
            }
        }
    }
    if(last == -1){
        cout<<0<<endl;
        cout<<endl;
        return;
    }
    vector<int> ans;
    int flip= 0;

    for(int i=last-1;i>=1;i--){
        bool positive = arr[i]>0;
        if(flip) positive=!positive;
        if(positive){
            ans.push_back(i);
            flip ^= 1;
        }
    }

    ans.push_back(last);
    cout<<ans.size()<<endl;
    for(int x : ans) {
        cout<<x<<" ";
    }
    cout<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}