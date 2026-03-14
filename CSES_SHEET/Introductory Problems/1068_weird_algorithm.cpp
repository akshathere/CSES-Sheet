#include <iostream>
#include <vector>

using namespace std;
int main()
{
    long long p;
    cin>>p;
    vector<long long> ans;
    while(p!=1){
        ans.push_back(p);
        if(p%2){
            p=p*3+1;
        }else p/=2;
    }
    ans.push_back(1);
    for(size_t i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}