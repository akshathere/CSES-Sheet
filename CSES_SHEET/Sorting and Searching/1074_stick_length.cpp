#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long findDiff(int x,vector<int> arr){
    int a=arr[x];
    long long diff=0;
    for(size_t i=0;i<arr.size();i++){
        diff+=abs(a-arr[i]);
    }
    return diff;
}
int main()
{
    int n;
    vector<int> arr;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }

    sort(arr.begin(),arr.end());
    if(n%2==0){
        int x=n/2;
        int y=(n/2)+1;
        cout<<min(findDiff(x,arr),findDiff(y,arr))<<endl;
    }else{
        int x=n/2;
        cout<<findDiff(x,arr)<<endl;
    }
    return 0;
}