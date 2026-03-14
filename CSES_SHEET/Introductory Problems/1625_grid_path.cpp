#include <iostream>
using namespace std;

string s;
bool visited[7][7];
int total_path=0;
bool is_inbound(int i,int j){
    if(i<0 || i>6 || j<0 || j>6) return false;
    return true;
}
void dfs(int i,int j,int step){

    if(step==48 || (i==6 && j==0)){
        total_path+=(step==48 && (i==6 && j==0));
        return;
    }

    // box in optimisation
    if((!is_inbound(i-1,j) || visited[i-1][j]) && (!is_inbound(i+1,j) || visited[i+1][j]))
        if(is_inbound(i,j-1) && !visited[i][j-1] && is_inbound(i,j+1) && !visited[i][j+1])
            return;
    if((!is_inbound(i,j-1) || visited[i][j-1]) && (!is_inbound(i,j+1) || visited[i][j+1]))
        if(is_inbound(i-1,j) && !visited[i-1][j] && is_inbound(i+1,j) && !visited[i+1][j])
            return;

    visited[i][j]=true;
    if((s[step]=='?' || s[step]=='U') && i>0 && !visited[i-1][j])
        dfs(i-1,j,step+1);

    if((s[step]=='?' || s[step]=='D') && i<6 && !visited[i+1][j])
        dfs(i+1,j,step+1);

    if((s[step]=='?' || s[step]=='L') && j>0 && !visited[i][j-1])
        dfs(i,j-1,step+1);

    if((s[step]=='?' || s[step]=='R') && j<6 && !visited[i][j+1])
        dfs(i,j+1,step+1);

    visited[i][j]=false;
}

int main(){
    cin>>s;
    visited[0][0] = true;
    dfs(0,0,0);
    cout<<total_path;
    return 0;
}