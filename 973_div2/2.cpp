/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
void helper(int l,vector<int>& visited,vector<int>& arr,vector<int>& dp){
    if(l==arr.size()-1) return 0;
    for(int k=0;k<arr.size();k++){
        for(int s=k+1;s<arr.size();s++){
            if(!visited[k] && !visited[s]){
                if(k>s){
                    visited[s]=1;
                    arr[s]=1e-9;
                    arr[k]=arr[k]-arr[s];
                    helper(l+1,visited,arr,dp);
                }
            }
        }
    }
}
// int helper(vector<int> arr){
//     int n=arr.size();
//     vector<int> visited(arr.size(),0);
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++)
//     }
// }
int main()
{
    int k;
    cin>>k;
    while(k--){
        int n;
        cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            arr.push_back(a);
        }
        vector<int> visited(n,0);
        vector<int> dp(n,0);
        helper(0,visited,arr,dp);
        for(int i=0)
    }
    

    return 0;
}