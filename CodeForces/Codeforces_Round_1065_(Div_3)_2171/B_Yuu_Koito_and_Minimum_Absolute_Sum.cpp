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
 
 
bool cmp(pair<string, int>& a, 
        pair<string, int>& b) 
{ 
    return a.second > b.second; 
}  

int ask(int i,int j){
    cout<<"? "<<i<<' '<<j<<endl;
    fflush(stdout);
    int r;
    cin>>r;
    return r;
}
void solve()
{
    ll n;
    ll m;
    ll r;
    ll w;
    ll c;
    ll a;
    ll b;
    ll k;
    ll o;
    string s;
    vector<ll> v2;
    vector<ll> v;
    map<string,int>mp;
    set<ll>st;
    cin >>n;
    
    for (int i = 0; i < n; i++)
    {
        cin>>o;
        v.push_back(o);
    }
    ll first = v[0];
        ll last = v[n-1];

        vector<ll> res = v;

        if (first != -1 && last != -1) {
            ll ans = llabs(last - first);
            for (int i = 0; i < n; i++)
                if (res[i] == -1)
                    res[i] = 0;
            cout << ans <<endl;
            for (ll x : res){
                 cout << x << " ";
                }
            cout <<endl;
            return;
        }

        ll ans = 0;

        if (first == -1 && last == -1) {
            res[0] = 0;
            res[n-1] = 0;
        } else if (first == -1) {
            res[0] = res[n-1];
        } else {
            res[n-1] = res[0];
        }

        for (int i = 0; i < n; i++){
            if (res[i] == -1)
                res[i] = 0;
        }
        cout << ans << "\n";
        for (ll x : res){
             cout << x << " ";}
        cout <<endl;

    
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
