#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
// ----------------------<MATH>---------------------------
template <typename T>
T gcd(T a, T b) { return (b ? __gcd(a, b) : a); }

template <typename T>
T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

bool cmp(pair<string, int> &a,
         pair<string, int> &b)
{
    return a.second > b.second;
}

int ask(int i, int j)
{
    cout << "? " << i << ' ' << j << endl;
    fflush(stdout);
    int r;
    cin >> r;
    return r;
}
ll n;
bool med(ll md, ll k)
{
    return k % md == 0;
}
void binary(ll l, ll r, ll x, ll &ans)
{
    if (l > r)
    {
        return;
    }
    ll md = (r + l) / 2;
    if (med(md, x))
    {
        ans = max(md, ans);
        binary(md + 1, r, x, ans);
    }
    else
    {
        binary(md + 1, r, x, ans);
    }
}
void solve()
{

    ll m;
    ll w;
    ll a;
    ll b;
    ll k;
    ll o;
    ll ans = -1;
    vector<ll> v2;
    map<string, int> mp;
    set<ll> st;
    vector<ll> v;
    cin >> a >> b;
    ll g = gcd(a, b);
    cin >> n;
    ll l, r;
    for (int i = 1; i * i <= g; i++)
    {
        if (g % i == 0)
        {
            v.push_back(i);
            if (i * i != g)
            {
                v.push_back(g / i);
            }
        }
    }
    v.push_back(g);
    sort(all(v));
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        if (lower_bound(all(v), r) == v.end())
        {
            ans = v[v.size() - 1];
        }
        else if (*lower_bound(all(v), r) == r)
        {
            ans = r;
        }
        else
        {
            ans = *(lower_bound(all(v), r) - 1);
        }
        if (ans >= l)
        {
            cout << ans << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}