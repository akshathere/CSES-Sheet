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
        vector<long long> f(n+1);
        for(int i=1;i<=n;i++){
            long long a;
            cin>>a;
            f[i]=a;
        }
        vector<long long> a(n+1);

        for(int i=1;i<=n-2;i++){
            a[i+1] = (f[i] -2*f[i+1]+f[i+2])/2;
        }

        long long sum=0;
        for(int i=2;i<=n;i++) sum+=a[i]*(long long)(i-1);
        a[n]=(f[1]-sum)/(n-1);

        long long sum2=0;
        for(int i=3;i<=n;i++) sum2+=a[i]*(long long)(i-2);
        a[1]=f[2]-sum2;
        for(int i=1;i<=n;i++){
            if(i>1) cout<<" ";
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}