// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <set>
// #include <unordered_map>
// #include <deque>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> arr;
//     for(int i=0;i<n;i++){
//         int  a;
//         cin>>a;
//         arr.push_back(a);
//     }
//     multiset<int> ans;
//     for (int i=0;i<n;i++){
//        auto index=ans.upper_bound(arr[i]);
//        if(index!=ans.end()){
//             ans.erase(index);
//         }
//         ans.insert(arr[i]);
//     }
//     cout<<ans.size()<<endl;
//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <deque>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int  a;
        cin>>a;
        arr.push_back(a);
    }
    vector<int> ans;
    for (int i=0;i<n;i++){
        if(ans.size()==0){
            ans.push_back(arr[i]);
        }else{
            auto index=upper_bound(ans.begin(),ans.end(),arr[i]);
            if(index!=ans.end()){
                *index=arr[i]; 
            }
            else{
                ans.push_back(arr[i]);
            }
        }
    }
    cout<<ans.size()<<endl;
    return 0;
}