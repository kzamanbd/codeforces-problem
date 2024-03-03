#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

int main() {

    int n;
    cin >> n;
    int solved = 0;
    for (int i = 0; i < n; i++) {
        vector<int> pb(3);
        for (int j = 0; j < 3; j++) {
            cin >> pb[j];
        }
        int solution = count(pb.begin(), pb.end(), 1);
        if (solution >= 2) {
            solved++;
        }
    }
    cout << solved;
    return 0;
}