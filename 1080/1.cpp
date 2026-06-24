#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int p;
    cin>>p;
    while(p--){
        int s;
        cin>>s;
        bool a=false;
        bool b=false;
        for(int i=0;i<s;i++){
            int k;
            cin>>k;
            if(k==67){
                a=true;
            }
        }
        if(a) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}