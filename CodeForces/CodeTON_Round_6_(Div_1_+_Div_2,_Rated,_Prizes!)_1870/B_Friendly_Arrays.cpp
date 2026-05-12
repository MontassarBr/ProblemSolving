#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> ordered_set;
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
const ll N=101;
vector<bool>isPrime(N,true);vector<ll>p;
void linear_sieve()
{
    isPrime[0]=isPrime[1]=0;
    for(ll i=2;i<N;i++)
    {
        if(isPrime[i]==1) p.push_back(i);
        for(ll o=0;o<p.size();o++)
        {
            if(i*p[o]>=N) break;
            isPrime[i*p[o]]=0;
            if(i%p[o]==0) break;
        }
    }
}
ll powmod(ll x, ll y)
{
    ll res = 1;
    x = x % MOD;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % MOD;
        y = y>>1;
        x = (x*x) % MOD;
    }
    return res;
}
vector<ll> fac,inv,finv;
void init(ll n)
{
    fac.resize(n+1);
    inv.resize(n+1);
    finv.resize(n+1);
    fac[0]=inv[0]=inv[1]=finv[0]=finv[1]=1;
    for(ll i=1;i<=n;++i)fac[i]=fac[i-1]*i%MOD;
    for(ll i=2;i<=n;++i)inv[i]=MOD-MOD/i*inv[MOD%i]%MOD;
    for(ll i=2;i<=n;++i)finv[i]=finv[i-1]*inv[i]%MOD;
}
ll nCr(ll x,ll y)
{
    if(x<0||y>x||y<0)return(0);
    return(fac[x]*finv[y]%MOD*finv[x-y]%MOD);
}
ll nPr(ll x,ll y)
{
    if(x<0||y>x||y<0)return 0;
    return fac[x]*finv[x-y]%MOD;
 }
bool cmp(vector<ll>& a, 
       vector<ll>& b) 
{ 
    return accumulate(all(a),0ll)>accumulate(all(b),0ll); 
} 
bool med(ll k,vector<ll>v,ll l){
    int p=v.size()/2;
 
    for (int i = p+1; i < v.size(); i++)
    {
        if (v[i]>k)
        {
            l-=v[i]-k;
            if (l<0)
            {
                break;
            }
            
        }
        else 
        {
            break;
        }
        
    }
    return l>=0;
    
}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int ask(int i,int j){
    cout<<"? "<<i<<' '<<j<<endl;
    fflush(stdout);
    int r;
    cin>>r;
    return r;
}
ll m,n,k;
vector<ll>v;vector<ll>v2;string res="";vector<ll>vv2; string s1;
    ll r;
    ll l;
    ll w;
    ll b;
    ll o;
    ll c;
    ll a;
    ll d,e,f;
bool ok(double m){
    ll c=0;
    for (int i = 0; i < n-1; i++)
    {
        if(v[i]<m/2) c++;
    }
    return c>n/2;
}
ll ans=INF;
vector<ll>dp(1000000,-1);
vector<ll>vis(1000000,0);
vector<vector<ll>>adj(1000000);
void dfs(ll u,ll p){
    if (adj[u].size() == 1 && p != -1) {
         c++;
         return;
    }
    for (auto v:adj[u]) {
        if (v!=p) {
            dfs(v,u);
        }
    }
}

void solve() {
    string s;
    string s1;
    string s2;
    string s3;
    v.clear();
    v2.clear();
    queue<pair<ll,ll>>pp;
    set<ll>st;
    set<ll>st1;
    ll p;
    vector<ll>v1;
    map<ll,ll>mp1;
    map<ll,ll>mp2;
    map<pair<ll,ll>,ll>C;
    cin>>n>>m;
    c=0;
   for (int i = 0; i < n; i++)
   {
    cin>>o;
    v.push_back(o);
    c^=o;
   }
    a=INF;
    b=0;
    for (int i = 0; i < m; i++)
    {
    cin>>o;
    a=min(a,o);
    b|=o;
    }
    v1=v;
    d=0;
    e=0;
    for (int i = 0; i < n; i++)
    {
        v[i]|=a;
        d^=v[i];
    }
    for (int i = 0; i < n; i++)
    {
        v1[i]|=b;
        e^=v1[i];
    }
    
   
   cout<<min({c,e})<<" "<<max({c,e})<<endl;
   
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //init(1e7);
   //linear_sieve();
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
         //cout << "Case #" << t << ": ";
        solve();
    }
}