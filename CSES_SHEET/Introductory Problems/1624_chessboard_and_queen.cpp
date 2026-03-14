#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <cstring>
using namespace std;
int hashmap[8][8];
bool canBePlaced(int i,int j){
    for(int k=0;k<i;k++){
            if(hashmap[k][j]==1){
                return false;
            }
    }
    int l=j-1;
    for(int k=i-1;k>=0;k--){
        if(l>=0){
            if(hashmap[k][l]==1){
                return false;
            }
            l--;
        }else break;
    }
    l=j+1;
    for(int k=i-1;k>=0;k--){
        if(l<8){
            if(hashmap[k][l]==1){
                return false;
            }
            l++;
        }else break;
    }
    return true;
}
long long helper(int i){
    if(i>=8) return 1LL;
    long long count=0;
    for(int j=0;j<8;j++){
        if(hashmap[i][j]==2) continue;
        if(i==0){
            if(canBePlaced(i,j)){
                hashmap[i][j]=1;
                count+=helper(i+1);
                hashmap[i][j]=0;
            }
        }else{
            if(canBePlaced(i,j)){
                hashmap[i][j]=1;
                count+=helper(i+1);
                hashmap[i][j]=0;
            }
        }
    }
    return count;
}
int main()
{
    vector<string> s;
    for(int i=0;i<8;i++){
        string a;
        cin>>a;
        s.push_back(a);
    }

    memset(hashmap,0,sizeof(hashmap));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(s[i][j]=='*')
                hashmap[i][j]=2;
        }
    }
    cout<<helper(0)<<endl;
    return 0;
}