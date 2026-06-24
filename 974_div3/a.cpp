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
    int p;
    cin>>p;
    while(p--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int c;
            cin>>c;
            arr.push_back(c);
        }
        int c1=0;
        int c2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0 && c2!=0){
                c1++;
                c2--;
            }else if(arr[i]>=k){
                c2+=arr[i];
            }
        }
        cout<<c1<<endl;

    }
    

    return 0;
}