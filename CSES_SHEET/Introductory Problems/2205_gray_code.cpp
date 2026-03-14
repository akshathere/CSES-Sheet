#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// in order to create gray code numbers first we need to write number in order for n-1 and then reverse them and push them to the
// answer and insert 0 in front of first n-1 numbers and 1 in front of second n-1 numbers
// need to be learn only ig.... GRAY CODE
void helper(int i,vector<string>& ans){
    if(i==1){
        ans.push_back("0");
        ans.push_back("1");
        return ;
    }
    helper(i-1,ans);
    vector<string> a=ans;
    reverse(a.begin(),a.end());
    for(int i=0;i<ans.size();i++){
        ans[i].insert(0,1,'0');
    }
    int n=ans.size();
    for(int i=0;i<n;i++){
        ans.push_back(a[i]);
        ans[i+n].insert(0,1,'1');
    }
}
int main()
{
    int p;
    cin>>p;
    vector<string> ans;
    helper(p,ans);
    for(auto it: ans){
        cout<<it<<endl;
    }

    return 0;
}