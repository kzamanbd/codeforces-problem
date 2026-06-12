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
        string s;
        cin >> s;

        // move flips two bits k apart -> both in same residue class mod k.
        // it flips adjacent elements in that chain, preserving parity of 1s.
        // all zero reachable iff every residue group has even number of 1s.
        vector<int> cnt(k, 0);
        for (int i = 0; i < n; i++)
            if (s[i] == '1') cnt[i % k]++;

        bool ok = true;
        for (int r = 0; r < k; r++)
            if (cnt[r] & 1) { ok = false; break; }

        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
