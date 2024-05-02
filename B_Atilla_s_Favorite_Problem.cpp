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
        string str;
        cin >> n >> str;
        int res = 1;
        for (int i = 0; i < n; i++) {
            res = max(res, int(str[i] - 'a') + 1);
        }
        cout << res << endl;
    }
    return 0;
}