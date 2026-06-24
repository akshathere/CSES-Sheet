#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int p;
    cin>>p;
    while(p--){
        int n;
        cin >> n;

        vector<int> a(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<bool> visited(n+1, false);

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {

                vector<int> indices;
                int cur = i;

                // Traverse this component
                while (cur <= n && !visited[cur]) {
                    visited[cur] = true;
                    indices.push_back(cur);
                    cur *= 2;
                }

                vector<int> values;
                for (int idx : indices)
                    values.push_back(a[idx]);

                sort(indices.begin(), indices.end());
                sort(values.begin(), values.end());

                for (int j = 0; j < indices.size(); j++) {
                    a[indices[j]] = values[j];
                }
            }
        }

        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i+1]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}