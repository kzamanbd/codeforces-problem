#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

void solve(vector<int> arr, int i) {
    if (i > arr.size() - 1) {
        return;
    }
    solve(arr, i + 1);
    if (i % 2 == 0) {
        cout << arr[i] << " ";
    }
}

int main() {

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solve(arr, 0);
    return 0;
}