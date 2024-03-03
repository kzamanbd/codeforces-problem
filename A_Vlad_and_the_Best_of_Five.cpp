#include <bits/stdc++.h>
using namespace std;

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        string str;
        cin >> str;
        char mx = str[0];
        int cnt = INT_MIN;
        for (char ch : str) {
            int c = count(str.begin(), str.end(), ch);
            if (cnt < c) {
                cnt = c;
                mx = ch;
            }
        }
        cout << mx << endl;
    }
    return 0;
}