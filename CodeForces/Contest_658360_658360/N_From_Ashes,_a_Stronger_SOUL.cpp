#include <bits/stdc++.h>

#define boAshraf ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define sz(s) (int)(s).size()
#define all(s) (s).begin(),(s).end()
using namespace std;

void File();

void sol();

int main() {
    boAshraf
    File();
    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}

void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    multiset<int> curr;
    for(auto &it:a)cin>>it,curr.emplace(it);
    vector<int> once;
    vector<pair<int, int>> reuse;
    int ans = 0;
    for(auto &it:b)cin>>it;
    for (int i = 0; i < m; i++) {
        int c;cin>>c;
        if (!c) once.emplace_back(b[i]);
        else reuse.emplace_back(b[i], c);
    }
    sort(all(reuse));
    for (auto &[init, nw]: reuse) {
        auto it = curr.lower_bound(init);
        if (it == curr.end()) break;
        ans++;
        int mx = max(*it, nw);
        curr.erase(it);
        curr.insert(mx);
    }
    for (auto &x: once) {
        auto it = curr.lower_bound(x);
        if (it == curr.end()) continue;
        ans++;
        curr.erase(it);
    }
    cout << ans << endl;
}

void File() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
