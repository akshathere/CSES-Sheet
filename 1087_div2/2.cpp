#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <algorithm>
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
        for(int i=0;i<n;i++){
            int greater=0;
            int smaller=0;
            for(int j=i+1;j<n;j++){
                if(arr[i]<arr[j]){
                    smaller++;
                }else if(arr[i]>arr[j]){
                    greater++;
                }
            }
            cout<<max(smaller,greater)<<" ";
        }
        cout<<endl;
    }
    return 0;
}