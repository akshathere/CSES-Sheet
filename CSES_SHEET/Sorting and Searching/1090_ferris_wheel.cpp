#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    int x;
    cin>>n>>x;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());

    int i=0;
    int j=n-1;
    int cnt=0;
    while(i<=j){
        if(arr[i]+arr[j]<=x){
            i++;
            j--;
        }else{
            j--;
        }
        cnt++;
    }
    if(i==j){
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}