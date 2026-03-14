#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    string p;
    cin>>p;

    unordered_map<char,int> mp;
    for(auto it: p){
        mp[it]++;
    }
    int oddCount=0;
    char c;
    for(auto it:mp){
        if((it.second)%2){
            c=it.first;
            oddCount++;
        }
    }
    if(oddCount>1){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    if((p.size()%2)==0 && oddCount==1){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    string s;
    for(auto it:mp){
        for(int i=0;i<(it.second)/2;i++){
            s.push_back(it.first);
        }
    }
    int n=s.size();
    if(oddCount) s.push_back(c);
    for(int i=n-1;i>=0;i--){
        s.push_back(s[i]);
    }
    cout<<s<<endl;
    return 0;
}