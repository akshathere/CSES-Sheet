#include <iostream>
#include <vector>

using namespace std;
int main()
{
    long long p;
    cin>>p;
    if(p==2 || p==3) cout<<"NO SOLUTION"<<endl;
    else{
        for(int i=2;i<=p;i+=2){
            cout<<i<<" ";
        }
        for(int i=1;i<=p;i+=2){
            cout<<i<<" ";
        }
    }
    return 0;
}