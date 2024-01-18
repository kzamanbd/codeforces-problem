#include <bits/stdc++.h>
using namespace std;

int main()
{

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        for (int i = 0; i < 3; i++)
        {
            string str;
            cin >> str;
            if (str.find("A") == -1)
            {
                cout << "A";
            }
            else if (str.find("B") == -1)
            {
                cout << "B";
            }
            else if (str.find("C") == -1)
            {
                cout << "C";
            }
        }
        cout << endl;
    }
    return 0;
}
