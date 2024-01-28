#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long triangles(const vector<int>& sticks) {
    int n = sticks.size();
    long long count = 0;

    sort(sticks.begin(), sticks.end());

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            int sum = sticks[i] + sticks[j];
            auto upper = upper_bound(sticks.begin() + j + 1, sticks.end(), sum);
            count += distance(sticks.begin() + j + 1, upper);
        }
    }

    return count;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        vector<int> sticks(n);
        for (int j = 0; j < n; ++j) {
            cin >> sticks[j];
            sticks[j] *= 2; // Multiply by 2 to get the actual length
        }

        cout << triangles(sticks) << endl;
    }

    return 0;
}
