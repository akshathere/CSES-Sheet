#include <iostream>
#include <vector>

using namespace std;
// we cannnot just add p/5 because numbers like 25 also divide by 5 and have 2 5's in it but contribute to only 1 so in order to
// get all the 5's we need to keep dividing it by 5's powers till it becomes <1
int main()
{
    long long p;
    cin>>p;
    long long sum=0;
    long long divisor=5;
    while(p/divisor>=1){
        sum+=(p/divisor);
        divisor*=5;
    }
    cout<<sum<<endl;
    return 0;
}