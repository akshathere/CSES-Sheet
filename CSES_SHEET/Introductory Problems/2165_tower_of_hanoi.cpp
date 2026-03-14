#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
void helper(int p,int start,int help,int end,vector<vector<int>>& ans){
    if(p==1){
        ans.push_back({start,end});
        return;
    }
    if(p==2){
        ans.push_back({start,help});
        ans.push_back({start,end});
        ans.push_back({help,end});
        return;
    }
    helper(p-1,start,end,help,ans);
    ans.push_back({start,end});
    helper(p-1,help,start,end,ans);
}
int main()
{
    int p;
    cin>>p;
    vector<vector<int>> ans;
    helper(p,1,2,3,ans);
    cout<<ans.size()<<endl;
    for(auto it: ans){
        cout<<it[0]<<" "<<it[1]<<endl;
    }
    return 0;
}