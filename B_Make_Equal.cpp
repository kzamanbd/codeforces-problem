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
        int total = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            total += arr[i];
        }

        int num = total / n;
        int carry = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] < num) {
                int need = num - arr[i];
                if (carry >= need) {
                    carry -= need;
                    arr[i] = num;
                }
            }
            else if (arr[i] > num) {
                carry += arr[i] - num;
                arr[i] = num;
            }
        }
        if (carry != 0) {
            cout << "NO";
        }
        else {
            cout << "YES";
        }
        cout << endl;
    }
    return 0;
}