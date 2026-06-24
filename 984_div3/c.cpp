
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> buildLPS(const string &pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int j = 0;  // length of the previous longest prefix suffix

    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = lps[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        lps[i] = j;
    }
    return lps;
}

// KMP search function to find occurrences of "1100" in the main string
bool KMPSearch(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = buildLPS(pattern);
    
    int i = 0;  // index for text
    int j = 0;  // index for pattern

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        if (j == m) {
            return true; // Pattern found
        }
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return false; // Pattern not found
}
int main()
{
    int p;
    cin>>p;
    while(p--){
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<pair<int,int>> arr;
        while(q--){
            int a,b;
            cin>>a>>b;
            char c;
            if(b==1) c='1';
            else c='0';
            s[a-1]=c;
            if(KMPSearch(s,"1100")) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}