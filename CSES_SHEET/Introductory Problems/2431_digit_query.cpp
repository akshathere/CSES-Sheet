#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <math.h>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;
int main()
{
    int p;
    cin>>p;
    while(p--){
        long long k;
        cin>>k;
        long long start=1;
        long long digits=1;
        long long count=9;
        while(k>(start + digits*count -1)){
            start+=digits*count;
            digits++;
            count*=10;
        }
        long long first= pow(10,digits-1);
        long long number_offset = (k-start) /digits;
        long long target_num= first + number_offset;

        string num_string = to_string(target_num);
        long long digit_offset = k-start;
        long long pos_in_num = digit_offset % digits;
        cout<<num_string[pos_in_num]<<endl;
    }
    return 0;
}