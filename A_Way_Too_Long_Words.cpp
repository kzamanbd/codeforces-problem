#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        string str;
        cin >> str;
        if (str.size() > 10) {
            cout << str.front() << str.size() - 2 << str.back();
        }
        else {
            cout << str;
        }
        cout << endl;
    }
    return 0;
}