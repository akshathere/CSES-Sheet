#include <iostream>
#include <vector>

using namespace std;

vector<int> findPattern(int n,int a,int b){
    vector<int> ans;
    for(int i=a+1;i<=n;i++){
        ans.push_back(i);
    }
    for(int i=1;i<=a;i++){
        ans.push_back(i);
    }
    return ans;
}
int main()
{
    long long p;
    cin>>p;
    while(p--){
        long long n;
        long long a;
        long long b;
        cin>>n>>a>>b;
        long long sum=a+b;
        if(a==0 && b==0){
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++){
                cout<<i<<" ";
            }
            cout<<endl;
            for(int i=1;i<=n;i++){
                cout<<i<<" ";
            }
        }else if((a==0 && b!=0) || (b==0 && a!=0)){
            cout<<"NO"<<endl;
        }else if(sum==n){
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++){
                cout<<i<<" ";
            }
            cout<<endl;
            vector<int> x=findPattern(n,a,b);
            for(int i=0;i<n;i++){
                cout<<x[i]<<" ";
            }
        }else if(sum<n){
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++){
                cout<<i<<" ";
            }
            cout<<endl;
            vector<int> x=findPattern(sum,a,b);
            for(size_t i=0;i<x.size();i++){
                cout<<x[i]<<" ";
            }
            
            for(int i=sum+1;i<=n;i++){
                cout<<i<<" ";
            }
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}