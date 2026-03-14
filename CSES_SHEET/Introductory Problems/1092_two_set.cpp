#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    long long p;
    cin>>p;
    long long sum=(p*(p+1))/2;
    // if even then only we can separate the set
    if(sum%2){
        cout<<"NO";
    }else{
        vector<long long> nums;
        unordered_map<int,int> mp;
        for(int i=0;i<p;i++){
            nums.push_back(i+1);
            mp[i+1]++;
        }
        vector<long long> set1;
        vector<long long> set2;
        
        long long sum1=sum/2;
        for(int i=p-1;i>=0;i--){
            if(sum1==0) break;
            if(sum1>=nums[i]){
                set1.push_back(nums[i]);
                sum1-=nums[i];
                mp.erase(nums[i]);
            }else{
                if(mp.find(sum1)!=mp.end()){
                    mp.erase(sum1);
                    set1.push_back(sum1);
                    break;
                }else{
                    cout<<"NO";
                    return 0;
                }
            }
        }
        for(auto it:mp){
            set2.push_back(it.first);
        }
        cout<<"YES"<<endl;
        cout<<set1.size()<<endl;
        for(size_t i=0;i<set1.size();i++){
            cout<<set1[i]<<" ";
        }
        cout<<endl;
        cout<<set2.size()<<endl;
        for(size_t i=0;i<set2.size();i++){
            cout<<set2[i]<<" ";
        }
    }
    return 0;
}   