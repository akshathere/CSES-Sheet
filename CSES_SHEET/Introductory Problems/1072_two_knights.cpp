#include <iostream>
#include <vector>

using namespace std;
int main()
{
    long long p;
    cin>>p;
    for(long long i=1;i<=p;i++){
        long long k=i*i;
        long long total= 1LL*(k *(k-1))/2;
        long long attackPositions= 2*(2*(i-1)*(i-2)); // 2*3 slabs horizontal and veritical and 2 positions in every 2*3 slabs are the positions attacked
        cout<<total-attackPositions<<endl;
    }
    return 0;
}