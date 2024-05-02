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

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        bool isSame = true;
        for (int i = 0; i < n; i++) {
            if (arr[i] != arr.front()) {
                isSame = false;
                break;
            }
        }

        if (isSame) {
            cout << "0" << endl;
        }
        else {
            int F = arr.front(), B = arr.back(), countFront = 0, countBack = 0;

            for (int i = 0; i < n; i++) {
                if (arr[i] == F) {
                    countFront++;
                }
                else {
                    break;
                }
            }

            for (int i = n - 1; i >= 0; i--) {
                if (arr[i] == B) {
                    countBack++;
                }
                else {
                    break;
                }
            }
            if (F == B) {
                cout << (n - (countFront + countBack)) << endl;
            }
            else {
                cout << (n - max(countFront, countBack)) << endl;
            }

        }
    }
    return 0;
}