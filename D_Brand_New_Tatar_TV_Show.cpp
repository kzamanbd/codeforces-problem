#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> c(n + 2, 0);
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            c[v]++;
        }

        // After the first removal sets threshold t, the position reduces to:
        //   c[t] even        -> mover wins;
        //   c[t] odd         -> mover wins iff some "losing" value lies in (t, t+k].
        // value t is losing iff c[t] is odd and no losing value in (t, t+k].
        // answer YES iff some present value is NOT losing (Arseniy starts there).
        // bit[] = Fenwick over values, marking losing values, for window queries.
        vector<int> bit(n + 2, 0);
        auto upd = [&](int i) {
            for (; i <= n; i += i & (-i)) bit[i]++;
        };
        auto qry = [&](int i) {
            int s = 0;
            for (; i > 0; i -= i & (-i)) s += bit[i];
            return s;
        };

        bool ans = false;
        for (int t = n; t >= 1; t--) {
            if (c[t] == 0) continue;
            if (c[t] % 2 == 0) { ans = true; continue; }
            int hi = min(n, t + k);
            int cntLosing = qry(hi) - qry(t);   // losing values in (t, t+k]
            if (cntLosing > 0) ans = true;       // non-losing -> Arseniy can start here
            else upd(t);                         // this value is losing
        }

        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}
