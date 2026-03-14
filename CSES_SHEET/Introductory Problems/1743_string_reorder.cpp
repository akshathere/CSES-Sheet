#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;
bool isPossible(unordered_map<char,int>& mp,char cur){
    char mode = cur;
    int total_left_to_fill = 0;
    for(auto& [ch,f] : mp){
        if(f>mp[mode]){
            mode=ch;
        }
        total_left_to_fill+=f;
    }
    return (mp[mode]<=(total_left_to_fill+1)/2) && (mp[cur] <= (total_left_to_fill/2));
}
int main()
{
    string s;
    cin>>s;
    unordered_map<char,int> mp;
    for(auto it: s){
        mp[it]++;
    }
    string ans;
        char prev = -1;
        for(size_t i=0;i<s.size();i++){
            for(char a= 'A';a<='Z';a++){
                if(mp.find(a)!=mp.end()){
                    if(mp[a]<=0 || prev==a) continue;
                    mp[a]--;
                    if(isPossible(mp,a)){
                            ans.push_back(a);
                            prev=a;
                            if(mp[a]==0){
                                mp.erase(a);
                            }
                            break;
                    }else{
                        mp[a]++;
                    }
                    
                }
            }
        }
        if(ans.size()==s.size())
        cout<<ans<<endl;
        else cout<<-1<<endl;
    
    return 0;
}