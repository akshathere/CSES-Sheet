#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    int n;
    int m;
    cin>>n;
    cin>>m;
    multiset<int> values;
    vector<int> maxValues;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        values.insert(a);
    }
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        maxValues.push_back(a);
    }
    for(int i=0;i<m;i++){
        auto it = values.upper_bound(maxValues[i]);
        if(it == values.begin()){
            cout << "-1\n";
        }
        else{
            it--;
            cout << *it << "\n";
            values.erase(it);
        }
    }
    return 0;
}