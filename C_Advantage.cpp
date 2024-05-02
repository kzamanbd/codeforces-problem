#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {

        int n;
        cin >> n;
        vector<int> arr(n);
        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            mx = max(mx, arr[i]);
        }
        vector<int> res(n);
        for (int i = 0; i < n - 1; i++) {
            res[i] = arr[i] - arr[i + 1];
        }
        res[n - 1] = arr[n - 1] - mx;
        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}