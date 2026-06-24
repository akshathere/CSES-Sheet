#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
 
void solve()
{
    long long n;
    cin>>n;
    int minPal[12]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 22, 11};
    int remainder= n % 12;
    long long a =minPal[remainder];

    if(n>=a){
        cout<<a<<" "<<n-a<<"\n";
    }
    else{
        cout<<-1<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}