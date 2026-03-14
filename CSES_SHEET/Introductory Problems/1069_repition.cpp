#include <iostream>
#include <vector>

using namespace std;
int main()
{
    string p;
    cin>>p;
    int prev=-1;
    int cnt=0;
    int maxi=0;
    for(size_t i=0;i<p.size();i++){
        if(prev==-1 || prev!=p[i]){
            cnt=1;
            prev=p[i];
        }else{
            cnt++;
        }
        maxi=max(maxi,cnt);
    }
    cout<<maxi<<endl;
    return 0;
}