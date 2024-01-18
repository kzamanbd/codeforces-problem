#include <bits/stdc++.h>
using namespace std;

int main()
{

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            total += v[i];
        }
        if (total % 2 == 0 && *max_element(v.begin(), v.end()) <= total / 2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}