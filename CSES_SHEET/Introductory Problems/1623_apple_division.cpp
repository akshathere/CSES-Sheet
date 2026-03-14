#include <iostream>
#include <vector>
#include <climits>
#include <map>
using namespace std;
vector<string> k;
void f(size_t i,vector<long long>& arr,long long sum,long long& totalSum,long long& ans){
    if(i>=arr.size()){
        return;
    }
    sum+=arr[i];
    if(sum!=totalSum)
        ans=min(ans,abs((totalSum-sum)-sum));
    f(i+1,arr,sum,totalSum,ans);
    sum-=arr[i];
    ans=min(ans,abs((totalSum-sum)-sum));
    f(i+1,arr,sum,totalSum,ans);
    
}
int main()
{
    long long p;
    cin>>p;
    vector<long long> arr;
    long long totalSum=0;
    for(long long i=0;i<p;i++){
        long long a;
        cin>>a;
        totalSum+=a;
        arr.push_back(a);
    }
    long long ans=LLONG_MAX;
    f(0,arr,0,totalSum,ans);
    cout<<ans<<endl;
    return 0;
}