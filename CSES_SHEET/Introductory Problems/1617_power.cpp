#include <iostream>
#include <vector>

using namespace std;
int MOD=1e9+7;

long long powerr(long long p){
    if(p==0) return 1;
    if(p%2){
        return 2*powerr(p-1)%MOD;
    }else{
        long long a=powerr(p/2)%MOD;
        return a*a%MOD;
    }
}
int main()
{
    long long p;
    cin>>p;
    long long ans= powerr(p)%MOD; 
    cout<< ans<<endl;
    return 0;
}   