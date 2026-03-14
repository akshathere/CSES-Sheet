#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    int prev=arr[0];
    int cnt=1;
    for(int i=1;i<n;i++){
        if(prev!=arr[i]){
            cnt++;
            prev=arr[i];
        }
    }
    cout<<cnt<<endl;
    return 0;
}