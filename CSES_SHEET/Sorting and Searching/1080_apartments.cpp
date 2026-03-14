#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    int m;
    int k;
    cin>>n>>m>>k;
    vector<int> required;
    vector<int> have;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        required.push_back(a);
    }
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        have.push_back(a);
    }
    sort(required.begin(),required.end());
    sort(have.begin(),have.end());
    int i=0;
    int j=0;
    int cnt=0;
    while(i<n && j<m){
        if(required[i]<=have[j]+k && required[i]>=have[j]-k){
            cnt++;
            i++;
            j++;
        }else{
            while(i<n && required[i]<(have[j]-k)){
                i++;
            }
            while(j<m && required[i]>(have[j]+k)){
                j++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}