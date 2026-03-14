#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> start;
    vector<int> end;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        int a;
        int b;
        cin>>a>>b;
        start.push_back(a);
        end.push_back(b);
        arr.push_back({b,a});
    }
    sort(arr.begin(),arr.end());
    int cnt=0;
    int et=-1;
    for(int i=0;i<arr.size();i++){
        if(et<=arr[i][1]){
            cnt++;
            et=arr[i][0];
        }
    }
    cout<<cnt<<endl;
    return 0;
}