#include <iostream>
#include <string>

using namespace std;

bool matchTemplate(const string& a, const string& b, const string& c) {
    int n = a.size();

    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            if (c[i] != a[i]) {
                return false;
            }
        }
        else {
            if (c[i] == a[i] || c[i] == b[i]) {
                continue;
            }
            else {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        string a, b, c;
        cin >> a >> b >> c;

        if (!matchTemplate(a, b, c)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
