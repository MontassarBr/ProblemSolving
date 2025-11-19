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
vector<int>adj[MAX_N];
int vis[1001][1001];

int cat[MAX_N];
char t1[1001][1001];
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
    cin >>n>>k;
    vector<vector<ll>>col(k+1);
    vector<vector<ll>>dif(k+1);
    
    for (int i = 1; i <= k; i++)
    {
        col[i].push_back(0);
    }
    for(int i=1;i<=n;i++){
       cin>>o;
       col[o].push_back(i);
    }
    for (int i = 1; i <= k; i++)
    {
        col[i].push_back(n+1);
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j <col[i].size()-1; j++)
        {
            dif[i].push_back(col[i][j+1]-col[i][j]-1);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        ll &f=*max_element(dif[i].begin(),dif[i].end());
        f/=2;
    }
    m=MAX_N;
    for (int i = 1; i <= k; i++)
    {
        m=min(m,*max_element(dif[i].begin(),dif[i].end()));
    }
    cout<<m<<endl;
    
    
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
