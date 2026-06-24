
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int p;
    cin>>p;
    while(p--){
        int n, k;
        cin >> n >> k;
        vector<string> strips(k);
        for (int i = 0; i < k; i++) {
            cin >> strips[i];
        }
        vector<int> allowed(n, 0);
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (int j = 0; j < k; j++) {
                mask |= 1 << (strips[j][i] - 'a');
            }
            allowed[i] = mask;
        }
        string ans;
        for (int d = 1; d <=n; d++) {
            if (n % d != 0) continue;
            bool ok =true;
            vector<int>chosen(d, 0);
            for (int r = 0; r < d; r++) {
                int inter = (1 << 26) - 1;
                for (int i = r; i < n; i += d) {
                    inter &= allowed[i];
                }
                if (inter == 0) {
                    ok = false;
                    break;
                }
                chosen[r] = inter;
            }

            if (!ok) continue;
            ans.resize(n);
            for (int r = 0; r < d; r++) {
                int c = __builtin_ctz(chosen[r]);
                for (int i = r; i < n; i += d) {
                    ans[i] = char('a' + c);
                }
            }
            break; // minimal d found
        }

        cout<<ans<<endl;
    }
    return 0;
}