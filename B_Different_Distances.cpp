#include <bits/stdc++.h>
using namespace std;

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        // 4 segments of length n; each number appears once per segment.
        // seg1: 1..n, seg2: 1..n, seg3: n,1,2,..,n-1 (shifted), seg4: 1..n
        // gaps per number stay pairwise distinct for all n.
        for (int i = 1; i <= n; i++) cout << i << " ";          // seg1
        for (int i = 1; i <= n; i++) cout << i << " ";          // seg2
        cout << n << " ";                                       // seg3 shifted
        for (int i = 1; i <= n - 1; i++) cout << i << " ";
        for (int i = 1; i <= n; i++) cout << i << " ";          // seg4
        cout << endl;
    }
    return 0;
}
