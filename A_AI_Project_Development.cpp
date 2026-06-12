#include <bits/stdc++.h>
using namespace std;

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        long long n, x, y, z;
        cin >> n >> x >> y >> z;

        // option 1: no AI, both write from start
        long long ans = (n + (x + y) - 1) / (x + y);

        // option 2: AI, first z hours only Maxim, then x + 10*y per hour
        for (long long h = 1; h <= ans; h++) {
            long long lines = x * h;
            if (h > z) lines += 10 * y * (h - z);
            if (lines >= n) {
                ans = min(ans, h);
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
