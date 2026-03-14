#include <iostream>
#include <vector>

using namespace std;
// we cannnot just add p/5 because numbers like 25 also divide by 5 and have 2 5's in it but contribute to only 1 so in order to
// get all the 5's we need to keep dividing it by 5's powers till it becomes <1
int main()
{
    long long p;
    cin>>p;
    while(p--){
        long long a;
        long long b;
        cin>>a>>b;
        if(a==b) {
            if(a%3==0){
                cout<<"YES"<<endl;
            }else cout<<"NO"<<endl;
        }else{
            if(a>b){
                long long x = 2*b - a;
                if(x>0 && (x%3==0) || (a==2*b)){
                    cout<<"YES"<<endl;
                }else cout<<"NO"<<endl;
            }else{
                long long x = 2*a - b;
                if(x>0 && (x%3==0) || (b==2*a)){
                    cout<<"YES"<<endl;
                }else cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}