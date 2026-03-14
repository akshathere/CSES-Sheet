#include <iostream>
#include <vector>

using namespace std;
int main()
{
    long long p;
    cin>>p;
    vector<long long> nums;
    long long sum=0;
    for(int i=0;i<p-1;i++){
         long long a;
         cin>>a;
         sum+=a;
         nums.push_back(a);
    }
    long long s=((p)*(p+1))/2;
    cout<<s-sum<<endl;
    return 0;
}   