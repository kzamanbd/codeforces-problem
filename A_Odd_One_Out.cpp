#include <bits/stdc++.h>
using namespace std;

int main()
{

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b)
        {
            cout << c;
        }
        else if (b == c)
        {
            cout << a;
        }
        else
        {
            cout << b;
        }
        cout << endl;
    }
    return 0;
}