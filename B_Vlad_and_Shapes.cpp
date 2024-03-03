#include <bits/stdc++.h>
using namespace std;

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<char>> grid(n, vector<char>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        vector<int> row(n, 0);

        for (int i = 0; i < n; i++) {
            row[i] = count(grid[i].begin(), grid[i].end(), '1');
        }

        sort(row.begin(), row.end());

        bool isSquare = false;
        for (int i = 0; i < row.size() - 1; i++) {
            if (row[i] != 0 && row[i] == row[i + 1]) {
                isSquare = true;
                break;
            }
        }
        if (isSquare) {
            cout << "SQUARE" << endl;
        }
        else {
            cout << "TRIANGLE" << endl;
        }
    }
    return 0;
}