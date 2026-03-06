#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<int>& a, int start, int need, vector<int>& cur, vector<vector<int>>& out) {
    if (need == 0) {
        out.push_back(cur);
        return;
    }
    int n = a.size();
    for (int i = start; i <= n - need; ++i) {
        cur.push_back(a[i]);
        dfs(a, i + 1, need - 1, cur, out);
        cur.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        
        vector<vector<int>>combos;
        vector<int> cur;
        dfs(a, 0, 7, cur, combos);
        
        cout << combos.size() << '\n';
        for (auto &comb : combos) {
            for (int i = 0; i < (int)comb.size(); ++i) {
                if (i) cout << ' ';
                cout << comb[i];
            }
            cout << '\n';
        }
    }
    return 0;
}
