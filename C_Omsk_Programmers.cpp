#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        long long a, b, x;
        cin >> a >> b >> x;

        // values reachable by repeated floor-division (i divisions -> A[i]).
        // after divisions only additions raise to a common target t.
        // meet at t = max(A[i], B[j]); cost = i + j + |A[i] - B[j]|.
        vector<long long> A, B;
        for (long long v = a;; v /= x) { A.push_back(v); if (v == 0) break; }
        for (long long v = b;; v /= x) { B.push_back(v); if (v == 0) break; }

        long long ans = LLONG_MAX;
        for (int i = 0; i < (int)A.size(); i++)
            for (int j = 0; j < (int)B.size(); j++)
                ans = min(ans, (long long)i + j + llabs(A[i] - B[j]));

        cout << ans << endl;
    }
    return 0;
}
