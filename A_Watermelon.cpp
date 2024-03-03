#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

int main() {

    int n;
    cin >> n;
    float res = (n * 1.0 / 2);
    bool isDecimal = res - (n / 2);
    if (isDecimal) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }
    return 0;
}