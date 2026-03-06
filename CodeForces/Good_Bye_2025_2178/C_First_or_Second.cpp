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
    ll w;
    ll a;
    ll b;
    ll k;
    ll o;
    ll n;
    vector<ll>v;
    vector<ll>vv;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>o;
        v.push_back(o);
    }

    
    vv.push_back(0);
    vv.push_back(v[0]);
    ll c=v[0];
    for (int i = 1; i < n; i++)
    {
        c+=llabs(v[i]);
        vv.push_back(c);
    }
    v.push_back(0);
    for (int i = 1; i < n+1; i++)
    {
        v[i]+=v[i-1];
    }
    ll res=LONG_LONG_MIN;
    for (int i = 0; i <n; i++)
    {
        res=max(res,(vv[i]-(v[n]-v[i])));
    }

    cout<<res<<endl;
    
    
    
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
