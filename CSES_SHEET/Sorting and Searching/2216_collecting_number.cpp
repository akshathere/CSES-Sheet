#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        int  a;
        cin>>a;
        mp[a]=i;
    }
    int cnt=1;
    for (int i=2;i<=n;i++){
        if(mp[i]<mp[i-1]){
            cnt++;
        }
    }

    cout<<cnt<<endl;
    return 0;
}