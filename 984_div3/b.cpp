
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    int p;
    cin>>p;
    while(p--){
        int n;
        int k;
        cin>>n;
        cin>>k;
        map<int,int> hash;
        for(int i=0;i<k;i++){
            int b;
            int c;
            cin>>b>>c;
            hash[b]+=c;
        }
        vector<int> pp;
        for(auto it:hash){
            pp.push_back(it.second);
        }
        sort(pp.begin(),pp.end(),greater<int>());
        int ans=0;
        for(int i=0;i<n;i++){
            if(pp.size()==i) break;
            ans+=pp[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}