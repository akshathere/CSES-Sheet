#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long x, y;
        cin >> n >> x >> y;

        vector<long long> a(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        // Case 1: no loss transfers (x == y)
        if (x == y) {
            cout << sum << "\n";
            continue;
        }

        // Case 2: lossy transfers
        long long ans = 0;
        
        // Try each bank as the target
        for (int i = 0; i < n; i++) {
            // Start with bank i having its original amount
            long long result = a[i];
            
            // Calculate how much we can transfer from all other banks
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    // Bank j can contribute (a[j] / x) * y to bank i
                    result += (a[j] / x) * y;
                }
            }
            
            ans = max(ans, result);
        }

        cout << ans << "\n";
    }

    return 0;
}