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

        // good array = permutation of consecutive ints.
        // need two index-disjoint length-L segments, each good, with
        // adjacent value ranges [m,m+L-1] and [m+L,m+2L-1] so the
        // concatenation (length 2L) is also good.
        // for each L slide a size-L window: valid iff distinct and
        // max-min==L-1; group windows by min value m, keep min-r,max-l.
        // a disjoint lower/upper pair at boundary m exists iff
        //   minR[m] < maxL[m+L]  or  minR[m+L] < maxL[m].
        vector<int> freq(n + 2, 0);
        vector<int> gMinR(n + 2, 0), gMaxL(n + 2, 0), ver(n + 2, 0);

        int ans = 0;
        for (int L = 1; L <= n / 2; L++) {
            for (int i = 1; i <= n; i++) freq[i] = 0;
            int dups = 0;
            deque<int> dmax, dmin;       // indices: values decreasing / increasing

            for (int i = 0; i < n; i++) {
                int v = a[i];
                if (++freq[v] == 2) dups++;
                while (!dmax.empty() && a[dmax.back()] <= v) dmax.pop_back();
                dmax.push_back(i);
                while (!dmin.empty() && a[dmin.back()] >= v) dmin.pop_back();
                dmin.push_back(i);

                if (i >= L) {
                    int ov = a[i - L];
                    if (freq[ov] == 2) dups--;
                    freq[ov]--;
                }
                while (dmax.front() <= i - L) dmax.pop_front();
                while (dmin.front() <= i - L) dmin.pop_front();

                if (i >= L - 1 && dups == 0) {
                    int mx = a[dmax.front()], mn = a[dmin.front()];
                    if (mx - mn == L - 1) {
                        int m = mn, l = i - L + 1, r = i;
                        if (ver[m] != L) {            // first window with this min value
                            ver[m] = L;
                            gMinR[m] = r;
                            gMaxL[m] = l;
                        } else {
                            if (r < gMinR[m]) gMinR[m] = r;
                            if (l > gMaxL[m]) gMaxL[m] = l;
                        }
                    }
                }
            }

            // check every boundary m: lower group m, upper group m+L
            bool ok = false;
            for (int m = 1; m + L <= n && !ok; m++) {
                if (ver[m] != L || ver[m + L] != L) continue;
                if (gMinR[m] < gMaxL[m + L] || gMinR[m + L] < gMaxL[m]) ok = true;
            }
            if (ok) ans = L;
        }
        cout << ans << "\n";
    }
    return 0;
}
