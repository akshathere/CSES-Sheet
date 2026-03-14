#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<string> k;
void f(string p,map<char,int>& mp,string s){
    if(s.size()==p.size()){
        k.push_back(s);
    }
    for(auto& it: mp){
        if(it.second>=1){
            it.second--;
            s.push_back(it.first);
            f(p,mp,s);
            it.second++;
            s.pop_back();
        }
    }
}
int main()
{
    string p;
    cin>>p;
    map<char,int> mp;
    for(auto it: p){
        mp[it]++;
    }
    f(p,mp,"");
    cout<<k.size()<<endl;
    for(auto it: k){
        cout<<it<<endl;
    }
    return 0;
}