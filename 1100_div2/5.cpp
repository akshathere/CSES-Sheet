#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long

bool can(int x,vector<int>& a,vector<int>& b){
    int n=a.size();
    int score = 0;
    bool last = false;
    for(int  i=0;i<n;i++){
        int cnt= 0 ;
        if(a[i]>=x) cnt++;
        if(b[i]>=x) cnt++;
        if(cnt==2){
            score++;
            last=false;
        }else if(cnt==0){
            if(!last){
                score--;
            }
            last=true;
        }
    }
    return score>0;
}
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n,0);
    vector<int> b(n,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x;
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b[i]=x;
    }
    int low =1;
    int high = 2*n;
    int ans = 0;
    while(low<=high){
        int mid = (low+high)/2;
        if(can(mid,a,b)){
            ans = mid;
            low = mid+1;
        }else high=mid-1;
    }
    cout<<ans<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}