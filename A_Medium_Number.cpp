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
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> res = { a, b,c };
        sort(res.begin(), res.end());
        cout << res[1] << endl;
    }
    return 0;
}