#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define vl vector<ll>
#define vi vector<int>
#define pi pair<int,int>
#define all(x) x.begin(),x.end()
#define range(i,n) for(int i=0;i<n;i++)
#define in_range(i,x,n) for(int i=x;i<n;i++)
#define fasterIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main() {

    fasterIO;

    int tc;
    cin >> tc;
    while (tc--) {
        // your code goes here
        string s;
        cin >> s;
        // check all char are same
        bool allSame = true;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1]) {
                allSame = false;
                break;
            }
        }

        if (allSame) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            reverse(s.begin(), s.end());
            cout << s << endl;
        }
    }
    return 0;
}