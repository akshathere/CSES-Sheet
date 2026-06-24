
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
        int q;
        cin>>q;
        int a=s/q;
        cout<<s-a<<endl;
    }
    return 0;
}