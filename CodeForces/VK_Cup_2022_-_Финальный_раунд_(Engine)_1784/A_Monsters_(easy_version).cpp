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
const ll N=1e6;
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
void init(int n)
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
bool cmp(pair<int,bitset<2>>& a, 
       pair<int,bitset<2>>& b) 
{ 
    return a.first > b.first; 
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
int ask(int i,int j){
    cout<<"? "<<i<<' '<<j<<endl;
    fflush(stdout);
    int r;
    cin>>r;
    return r;
}
ll m,n,c,k;vector<ll>v;vector<ll>v2;vector<ll>vv;vector<ll>vv2;
    ll r;
    ll l;
    ll w;
    ll a;
    ll b;
    ll o;
ll dp[MAX_N][2];
ll rec(ll i,ll c){
    if (i==n)
    {
        return 0;
    }
    if (dp[i][c]!=-1)
    {
        return dp[i][c];
    }
    ll r=rec(i+1,0)+(rec(i,c)-v[i]);
    ll b=rec(i+1,1)+(v2[i]-rec(i,c));
    return dp[i][c]=max(r,b);
}


bool can(ll md){
    return (md*b)+(min(((n-1)/7)+1,md*2)*c)>=a;
}

void solve() {

    string s;
    v.clear();
    vv.clear();
    v2.clear();
    vector<pair<ll,ll>>vp;
    priority_queue<ll>pp;
    unordered_map<ll,ll>mp;
    unordered_set<ll>st;
    char cc;
    cin>>n;
    c=0;
    v.push_back(0);
    for (int i = 0; i <n; i++)
    {
        cin>>o;
        v.push_back(o);
    }
    sort(all(v));

    for (int i = 0; i <n; i++)
    {
        if (v[i]!=v[i+1])
        {
            c+=v[i+1]-(v[i]+1);
            v[i+1]=v[i]+1;
        }                                 
    }
    cout<<c<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //init(MAX_N);
    //linear_sieve();
     cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        memset(dp,-1,sizeof dp);
         //cout << "Case #" << t << ": ";
        solve();
    }
}