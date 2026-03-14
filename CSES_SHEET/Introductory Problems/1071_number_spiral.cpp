#include <iostream>
#include <vector>

using namespace std;
int main()
{
    long long p;
    cin>>p;
    while(p--){
        long long a;
        long long b;
        cin>>a>>b;
        long long x=max(a,b);
        long long ans;
        if(x%2==0){
            if(a==x){
                ans= x*x - (b-1);
            }else{
                ans= (x-1)*(x-1) + (a);
            }
        }else{
            if(b==x){
                ans= x*x - (a-1);
            }else{
                ans= (x-1)*(x-1) + (b);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}