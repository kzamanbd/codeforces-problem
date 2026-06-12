#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // compress values to 0..D-1
        vector<int> sorted_vals(a.begin(), a.end());
        sort(sorted_vals.begin(), sorted_vals.end());
        sorted_vals.erase(unique(sorted_vals.begin(), sorted_vals.end()), sorted_vals.end());
        int D = sorted_vals.size();
        for (int i = 0; i < n; i++)
            a[i] = lower_bound(sorted_vals.begin(), sorted_vals.end(), a[i]) - sorted_vals.begin();

        vector<int> seen(D, 0);
        int ver = 0;
        // correctness check on current a after temporarily swapping i,j (i==j => no swap)
        auto isCorrect = [&](int i, int j) -> bool {
            swap(a[i], a[j]);
            ver++;
            bool ok = true;
            int prev = -1;
            for (int p = 0; p < n; p++) {
                if (a[p] != prev) {
                    if (seen[a[p]] == ver) { ok = false; break; }
                    seen[a[p]] = ver;
                    prev = a[p];
                }
            }
            swap(a[i], a[j]);
            return ok;
        };

        if (isCorrect(0, 0)) { cout << "YES\n"; continue; }

        // build runs
        vector<int> rval, rs, re;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && a[j] == a[i]) j++;
            rval.push_back(a[i]); rs.push_back(i); re.push_back(j - 1);
            i = j;
        }
        int m = rval.size();

        // m >= D always; two single intrusions add at most 4 runs
        if (m - D > 4) { cout << "NO\n"; continue; }

        // candidate cells: endpoints of runs whose value repeats, plus neighbour runs
        vector<int> runCnt(D, 0);
        for (int t = 0; t < m; t++) runCnt[rval[t]]++;
        set<int> candSet;
        for (int t = 0; t < m; t++) {
            if (runCnt[rval[t]] > 1) {
                for (int tt = t - 1; tt <= t + 1; tt++) {
                    if (tt >= 0 && tt < m) { candSet.insert(rs[tt]); candSet.insert(re[tt]); }
                }
            }
        }
        vector<int> cand(candSet.begin(), candSet.end());

        bool ans = false;
        for (int x = 0; x < (int)cand.size() && !ans; x++)
            for (int y = x + 1; y < (int)cand.size() && !ans; y++) {
                int i = cand[x], j = cand[y];
                if (a[i] == a[j]) continue;
                if (isCorrect(i, j)) ans = true;
            }

        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}
