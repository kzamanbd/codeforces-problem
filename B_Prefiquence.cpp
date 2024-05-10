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
        int n, m;
        cin >> n >> m;

        string a, b;
        cin >> a >> b;

        int k = 0, j = 0;
        for (int i = 0; i < m && j < n; i++) {
            if (b[i] == a[j]) {
                j++;
                k++;
            }
        }
        cout << k << endl;
    }
    return 0;
}