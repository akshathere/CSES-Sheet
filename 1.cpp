/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
void swapRow(vector<int>& arr1, vector<int>& arr2) {
    for (int i = 0; i < arr1.size(); i++) {
        int temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }
}

void swapRows(vector<vector<int>>& arr) {
    for (int i = 0; i < arr.size() - 1; i += 2) { // Increase by 2 to swap each pair only once
        swapRow(arr[i], arr[i + 1]);
    }
}
void swapCols(vector<vector<int>>& arr){
    for(int i=0;i<arr[0].size()-1;i++){
        for(int j=0;j<arr.size();j++){
            int temp=arr[j][i];
            arr[j][i]=arr[j][i+1];
            arr[j][i+1]=temp;
        }
    }
}
int main()
{
    int k;
    cin>>k;
    vector<vector<vector<int>>> ppp;
    for(int i=0;i<k;i++){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> arr(n);
        for(int x=0;x<n;x++){
            for(int y=0;y<m;y++){
                int p;
                cin>>p;
                arr[x].push_back(p);
            }
        }
        ppp.push_back(arr);
        
        
    }
    for(int i=0;i<ppp.size();i++){
        int n=ppp[i].size();
        int m=ppp[i][0].size();
        if(n>m){
            swapRows(ppp[i]);
        }else{
            swapCols(ppp[i]);
        }
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                cout<<ppp[i][x][y]<<" ";
            }
            cout<<endl;
        }
    }
    

    return 0;
}