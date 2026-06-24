#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <algorithm>
using namespace std;
int main()
{

    int n;
    int c;
    int k;
    vector<int> arr;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        pq.push(a);
    }
    long long ans=0;
    while(!pq.empty()){
        long long a= pq.top();
        if(a<c){
            long long z= max(k-a,k);
            ans+=z;
            z-=k;
            if(k<0) break;
        }else{
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}