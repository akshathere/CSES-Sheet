#include <iostream>
#include <vector>

using namespace std;
int main()
{
    long long p;
    cin>>p;
    vector<long long> nums;
    long long sum=0;
    long long prev=-1;
    for(int i=0;i<p;i++){
         long long a;
         cin>>a;
         if(prev==-1) prev=a;
         else{
            if(a<prev){
                sum+=(prev-a);
            }else prev=a;
         }
         nums.push_back(a);
    }
    cout<<sum<<endl;
    return 0;
}   