#include <bits/stdc++.h>
using namespace std;

int matchedPairs(const string &s, const vector<char> &del) {
    int open = 0, p = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (del[i]) continue;
        if (s[i] == '(') open++;
        else if (open > 0) { open--; p++; }
    }
    return p;
}

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<char> del(n, 0);
        int d = min(k, matchedPairs(s, del));   // pairs to destroy

        // Each step delete one bracket that strictly lowers the matching:
        //  - delete close c if no unmatched ')' lies after its open o
        //  - else delete open o if no unmatched '(' lies before its close c
        for (int step = 0; step < d; step++) {
            vector<int> st;            // indices of kept, currently-open '('
            int lastUC = -1;           // last unmatched ')'
            int maxO = -1, maxO_close = -1;   // matched pair with largest open
            int minC = INT_MAX, minC_open = -1; // matched pair with smallest close
            for (int i = 0; i < n; i++) {
                if (del[i]) continue;
                if (s[i] == '(') st.push_back(i);
                else if (!st.empty()) {
                    int o = st.back(); st.pop_back();
                    if (o > maxO) { maxO = o; maxO_close = i; }
                    if (i < minC) { minC = i; minC_open = o; }
                } else lastUC = i;
            }
            if (maxO == -1) break;     // no matched pair left
            int firstUO = st.empty() ? INT_MAX : st.front(); // first unmatched '('

            if (maxO > lastUC) del[maxO_close] = 1;
            else if (minC < firstUO) del[minC_open] = 1;
            else del[maxO_close] = 1;  // fallback
        }

        string out(n, '0');
        for (int i = 0; i < n; i++) if (del[i]) out[i] = '1';
        cout << out << endl;
    }
    return 0;
}
