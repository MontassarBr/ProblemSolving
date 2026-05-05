#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define all(a) (a).begin(), (a).end()

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<pair<ll, int>> v(n);
    bool has_one = false;
    bool all_same = true;

    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1; // Store 1-based index
        if (v[i].first == 1) has_one = true;
        if (i > 0 && v[i].first != v[i-1].first) all_same = false;
    }

    // If already equal, 0 operations
    if (all_same) {
        cout << 0 << endl;
        return;
    }

    // If there is a 1 and other numbers, it's impossible
    if (has_one) {
        cout << -1 << endl;
        return;
    }

    vector<pair<int, int>> ops;

    // Keep reducing the maximum element using the minimum element
    while (true) {
        int mn_idx = 0;
        int mx_idx = 0;

        for (int i = 0; i < n; i++) {
            if (v[i].first < v[mn_idx].first) mn_idx = i;
            if (v[i].first > v[mx_idx].first) mx_idx = i;
        }

        // If min and max are the same, all elements are equal
        if (v[mn_idx].first == v[mx_idx].first) break;

        // Perform: v[mx] = ceil(v[mx] / v[mn])
        // Integer-only ceil: (a + b - 1) / b
        v[mx_idx].first = (v[mx_idx].first + v[mn_idx].first - 1) / v[mn_idx].first;
        
        // Store the indices of the operation
        ops.push_back({v[mx_idx].second, v[mn_idx].second});
    }

    // Output results
    cout << ops.size() << endl;
    for (auto &p : ops) {
        cout << p.first << " " << p.second << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    if (!(cin >> tc)) tc = 1;
    while (tc--) {
        solve();
    }
    return 0;
}