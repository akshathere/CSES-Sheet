#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> mp1(n+1,0);
    vector<int> arr;
    for(int i=0;i<n;i++){
        int  a;
        cin>>a;
        arr.push_back(a);
        mp1[a]=i;
    }
    int cnt=1;
        for (int i=2;i<=n;i++){
            if(mp1[i]<mp1[i-1]){
                cnt++;
            }
    }
    for(int k=0;k<m;k++){
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        int x=arr[a-1];
        int y=arr[b-1];

        if((x+1)<=n && (mp1[x+1])>a-1 && (mp1[x+1])<b-1){
            cnt++;
        }
        if((x-1)>0 && (mp1[x-1])>a-1 && (mp1[x-1])<b-1){
            cnt--;
        }
        if((y+1)<=n && (mp1[y+1])>a-1 && (mp1[y+1])<b-1){
            cnt--;}
        if((y-1)>0 && (mp1[y-1])>a-1 && (mp1[y-1])<b-1){
            cnt++;}

        if(x ==(y+1)){
            cnt--;
        }
        if(x ==(y-1)) cnt++;
        mp1[x]=b-1;
        mp1[y]=a-1;
        int c=x;
        arr[a-1]=arr[b-1];
        arr[b-1]=c;
        cout<<cnt<<endl;
    }
    
    return 0;
}