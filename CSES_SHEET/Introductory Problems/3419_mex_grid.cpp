#include <iostream>
#include <vector>

using namespace std;
int main()
{
    long long p;
    cin>>p;
    for(int i=0;i<p;i++){
        for(int j=0;j<p;j++){
            cout<<(i^j)<<" ";
        }
        cout<<endl;
    }
    return 0;
}