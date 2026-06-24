#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int p;
    cin>>p;
    while(p--){
        int n;
        cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            arr.push_back(a);
        }
        if(n==1 || n==2){
            cout<<"-1"<<endl;
            continue;
        }
        sort(arr.begin(),arr.end());
        // int maxi=arr[n-1];
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        float avg=(sum/n)/2;
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]<avg) count++;
        }
        if(count>n/2){
            cout<<"0"<<endl;
        }
        else{
            int num=arr[floor(n/2)];
            num*=2;
            num*=n;
            int ans=num-sum+1;
            cout<<ans<<endl;
        }

    }
    

    return 0;
}