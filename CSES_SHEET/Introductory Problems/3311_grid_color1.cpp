#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<int> findPattern(int n,int a,int b){
    vector<int> ans;
    for(int i=a+1;i<=n;i++){
        ans.push_back(i);
    }
    for(int i=1;i<=a;i++){
        ans.push_back(i);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<string> s;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        s.push_back(a);
    }
    vector<vector<int>> ss = {{0,-1},{-1,0}};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            set<char> notAllowed;
            notAllowed.insert(s[i][j]);
            for(auto it: ss){
                int x=i+it[0];
                int y=j+it[1];
                if(x>=0 && x<n && y>=0 && y<m){
                    notAllowed.insert(s[x][y]);
                }
            }
            for(int k=0;k<4;k++){
                char c = 'A'+k;
                if(notAllowed.find(c)==notAllowed.end()){
                    s[i][j]=c;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<s[i][j];
        }
        cout<<endl;
    }
    return 0;
}