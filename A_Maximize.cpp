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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {

    fasterIO;

    int tc;
    cin >> tc;
    while (tc--) {
        int x;
        cin >> x;

        int maxSum = 0, maxY = 0;
        for (int y = 1; y < x; ++y) {
            int currentSum = gcd(x, y) + y;
            if (currentSum > maxSum) {
                maxSum = currentSum;
                maxY = y;
            }
        }

        cout << maxY << endl;
    }
    return 0;
}