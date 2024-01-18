#include <bits/stdc++.h>
using namespace std;

int main() {

    int testCase;
    cin >> testCase;
    while (testCase--) {
        int length;
        cin >> length;

        vector<char> box1(length);
        vector<char> box2(length);

        for (int i = 0; i < length; i++) {
            cin >> box1[i];
        }
        for (int i = 0; i < length; i++) {
            cin >> box2[i];
        }

        int days = 0;

        for (int i = 0; i < length; ++i) {
            if (box1[i] == '1' && box2[i] == '0') {
                days++;
            }
            else if (box1[i] == '0' && box2[i] == '1') {
                days++;
            }
        }

        cout << days << endl;
    }
    return 0;
}