#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <math.h>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    int p;
    cin>>p;
    vector<vector<int>> arr(p,vector<int> (p,INT_MAX));
    queue<pair<int,int>> q;
    vector<vector<int>> x = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
    q.push({0,0});
    arr[0][0]=0;
    while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(int j=0;j<8;j++){
                int z=it.first+x[j][0];
                int y=it.second+x[j][1];
                if(z>=0 && z<p && y>=0 && y<p && arr[z][y]==INT_MAX){
                    arr[z][y]=arr[it.first][it.second]+1;
                    q.push({z,y});
                }
            }
    }
    for(int i=0;i<p;i++){
        for(int j=0;j<p;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}