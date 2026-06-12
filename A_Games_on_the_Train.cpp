#include <bits/stdc++.h>
using namespace std;

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int mn = INT_MAX, mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            int h;
            cin >> h;
            mn = min(mn, h);
            mx = max(mx, h);
        }

        // x_i = T - h_i with 1 <= x_i <= k, all reach T.
        // smallest T = mx + 1, so min k = mx - mn + 1.
        cout << mx - mn + 1 << endl;
    }
    return 0;
}
