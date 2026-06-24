
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int p;
    cin>>p;
    while(p--){
        vector<int> arr;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            arr.push_back(a);
        }
        if(arr.size()<=1) cout<<"NO"<<endl;
        else{
            int flag=0;
            for(int i=1;i<n;i++){
                if(abs(arr[i-1]-arr[i])!=5 && abs(arr[i-1]-arr[i])!=7){
                    flag=1;
                    cout<<"NO"<<endl;
                    break;
                }
            }
            if(flag==0) cout<<"YES"<<endl;
        }
    }
    return 0;
}