/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int k;
    cin>>k;
    while(k--){
        int n;
        cin>>n;

        int x;int y;
        cin>>x>>y;
        int ans=n/(min(x,y));
        if(n%(min(x,y))!=0){
            ans++;
        }
        cout<<ans<<endl;
    }
    

    return 0;
}