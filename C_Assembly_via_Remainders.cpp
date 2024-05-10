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
        int n;
        cin >> n;
        vi arr(n);
        range(i, n - 1) cin >> arr[i];

        vi res(n);
        res[0] = arr[0] + 1;

        for (int i = 1; i < n; i++) {
            res[i] = arr[i] % arr[i] - 1;
        }
        for (auto x : res) {
            cout << x << " ";
        }
        cout << endl;


    }
    return 0;
}