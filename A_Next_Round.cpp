#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

int main() {

    int n, search;
    cin >> n >> search;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > search) {
            count++;
        }
    }
    cout << count;
    return 0;
}