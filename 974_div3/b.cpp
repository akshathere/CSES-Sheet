/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    int p;
    cin>>p;
    while(p--){
       int n;int k;
       cin>>n>>k;
       int ans=(n*(n+1))/2 - ((n-k)*(n-k+1))/2;
       

       if(ans%2) cout<<"NO"<<endl;
       else cout<<"YES"<<endl;
    }
    

    return 0;
}