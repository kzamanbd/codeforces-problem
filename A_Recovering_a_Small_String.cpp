#include <bits/stdc++.h>
using namespace std;

vector<int> recovery(int n) {
    vector<int> res;
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (i + j + k == n && i <= 26 && j <= 26 && k <= 26) {
                    res.push_back(i - 1);
                    res.push_back(j - 1);
                    res.push_back(k - 1);
                    return res;
                }
            }
        }
    }
    return res;
}

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        vector<int> res = recovery(n);

        for (int val : res) {
            cout << char(val + 'a');
        }
        cout << endl;

    }
    return 0;
}