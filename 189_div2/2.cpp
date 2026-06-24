#include <iostream>
#include <vector>

using namespace std;
bool check(const string& s, int start) {
    int n = s.size();
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        char expected = ((i + start) % 2 == 0) ? 'a' : 'b';
        if (s[i] != expected) {
            if (l == -1) l = i;
            r = i;
        }
    }
    if (l == -1) return true;
    {
        bool ok = true;
        int len = r - l + 1;
        for (int i = 0; i < len && ok; i++) {
            char expected = (((l + i) + start) % 2 == 0) ? 'a' : 'b';
            char got = s[r - i]; // reversed
            if (got != expected) ok = false;
        }
        if (ok) return true;
    }
    {
        bool ok = true;
        int len = r - l + 1;
        for (int i = 0; i < len && ok; i++) {
            char expected = (((l + i) + start) % 2 == 0) ? 'a' : 'b';
            char got = (s[r - i] == 'a') ? 'b' : 'a';
            if (got != expected) ok = false;
        }
        if (ok) return true;
    }
    
    return false;
}

int main()
{
    int t;
    cin >> t;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        long long m = y / x;
        
        if (m <= 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}