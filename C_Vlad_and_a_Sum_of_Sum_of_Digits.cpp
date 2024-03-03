#include <bits/stdc++.h>
using namespace std;

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        long long sum = 0;
        if (n > 9) {
            int countNine = n / 9;
            int mod = n % 9, nine = 9;
            int sumOfNine = nine * (nine + 1) / 2;
            int sumOfExtra = mod * (mod + 1) / 2;
            cout << countNine << " " << mod << " " << sumOfNine << " " << sumOfExtra << endl;
            sum = (countNine * sumOfNine) + sumOfExtra;
        }
        else {
            sum = n * (n + 1) / 2;
        }

        cout << sum << endl;
    }
    return 0;
}