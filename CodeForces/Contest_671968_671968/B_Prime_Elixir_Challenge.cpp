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
const int N = 1e7 + 100;
vector<bool> isPrime(N, true);
vector<int> p;
void linear_sieve()
{
    isPrime[0] = isPrime[1] = 0;
    for (ll i = 2; i < N; i++)
    {
        if (isPrime[i] == 1)
            p.push_back(i);
        for (ll o = 0; o < p.size(); o++)
        {
            if (i * p[o] >= N)
                break;
            isPrime[i * p[o]] = 0;
            if (i % p[o] == 0)
                break;
        }
    }
}

void fact(int x, map<ll, ll> &f)
{
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int c = 0;
            while (x % i == 0)
            {
                x /= i;
                c++;
            }
            f[i] += c;
        }
    }
    if (x > 1)
    {
        f[x]++;
    }
}
bool cmp(pair<string, int> &a,
         pair<string, int> &b)
{
    return a.second > b.second;
}
bool med(ll k, vector<ll> v, ll l)
{
    int p = v.size() / 2;

    for (int i = p + 1; i < v.size(); i++)
    {
        if (v[i] > k)
        {
            l -= v[i] - k;
            if (l < 0)
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
    return l >= 0;
}
int knowbit(int i, int n)
{
    return (n >> i) & 1;
}
bool check(vector<int> v)
{
    int c = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] % 2 == 0)
        {
            c++;
        }
        if (c > v.size() / 2)
        {
            return true;
        }
    }
    return false;
}

void solve()
{
    ll n;
    ll r;
    ll l;
    ll w;
    ll c;
    ll a;
    ll b;
    ll k;
    ll o;
    ll q;
    string s;
    vector<ll> v;
    vector<ll> v2;
    vector<ll> v3;
    map<ll, ll> f;
    cin >> n;
    ll ss = 0;
    for (ll k = 0; k < n; k++)
    {
        cin >> o;
        v.push_back(o);
        c = lower_bound(all(p), o) - p.begin();
        if (p[c] > o)
        {
            ss += (o - p[c - 1]);
        }
        else
            ss += (o - p[c]);
    }
    cout << ss << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}