#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
 
void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> sorted = arr;
    sort(sorted.begin(),sorted.end());
    sorted.erase(unique(sorted.begin(),sorted.end()),sorted.end());
    int k =sorted.size();
    for(int i=0;i<n;i++){
        arr[i] = lower_bound(sorted.begin(),sorted.end(),arr[i]) - sorted.begin();
    }

    vector<int> C(k,0);

    for(int i=0;i<n;i++){
        C[arr[i]]++;
    }

    int check_id = 0;
    vector<int> seen(k,-1);
    auto isValid = [&](const vector<int>& arr){
        check_id++;
        seen[arr[0]]= check_id;
        for(int i=1;i<n;i++){
            if(arr[i]!=arr[i-1]){
                if(seen[arr[i]]== check_id) return false;
                seen[arr[i]]= check_id;
            }
        }
        return true;
    };
    if(isValid(arr)){
        cout<<"YES\n";
        return;
    }
    vector<int> pref_count (k,0);

    int L1 = -1;
    for(int i=0;i<n-1;i++){
        pref_count[arr[i]]++;
        if(arr[i]!=arr[i+1] && pref_count[arr[i]]<C[arr[i]]){
            L1=i;
            break;
        }
    }
    vector<int> suffCount(k,0);
    int R1 = -1;
    for(int i=n-1;i>=1;i--){
        suffCount[arr[i]]++;
        if(arr[i]!=arr[i-1] && suffCount[arr[i]]<C[arr[i]]){
            R1=i;
            break;
        }
    }
    vector<int> firstPos(k,-1),lastPos(k,-1);
    for(int i=0;i<n;i++){
        if(firstPos[arr[i]]==-1) firstPos[arr[i]]=i;
        lastPos[arr[i]]=i;
    }

    vector<int> candi;
    auto add_val = [&](int val){
        if(val>=0 && val<k){
            if(firstPos[val]!=-1) candi.push_back(firstPos[val]);
            if(lastPos[val]!=-1) candi.push_back(lastPos[val]);
        }
    };
    if(L1!=-1){
        for(int d=-2;d<=2;d++) {
            if(L1+d>=0 && L1+d< n) {
                add_val(arr[L1+d]);
                candi.push_back(L1+d);
            }
        }
    }
    if(R1!=-1){
        for(int d=-2;d<=2;d++) {
            if(R1+d>=0 && R1+d<n) {
                add_val(arr[R1+d]);
                candi.push_back(R1 + d);
            }
        }
    }
    add_val(arr[0]);
    candi.push_back(0);
    add_val(arr[n-1]);
    candi.push_back(n-1);
    sort(candi.begin(),candi.end());
    candi.erase(unique(candi.begin(),candi.end()),candi.end());

    bool posi=false;
    for(size_t i=0;i<candi.size();i++){
        for(size_t j=i+1;j<candi.size();j++){
            int u = candi[i];
            int v = candi[j];
            if(arr[u]==arr[v]) continue;
            swap(arr[u],arr[v]);
            if(isValid(arr)){
                posi=true;
            }
            swap(arr[u],arr[v]);
            if(posi) break;
        }
        if(posi) break;
    }
    if(posi) cout<<"YES\n";
    else cout<<"NO\n";
    
}


 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}