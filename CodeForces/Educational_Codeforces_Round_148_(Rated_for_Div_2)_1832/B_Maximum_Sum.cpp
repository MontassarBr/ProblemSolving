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
const int MAX_N = 1e6 + 5;
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
ll m,n,c,k;
vector<ll>v;vector<ll>v2;vector<ll>vv;vector<ll>vv2;
/*vector<vector<pair<int,int>>>adj(MAX_N);
int vis[4][4];

ll res=0;
char cc[1000][1000];
vector<ll>sol(MAX_N,LONG_LONG_MAX);
ll dp[10000][10000];
vector<string>cm;
map<ll,ll>mm;
/*void bfs(int i){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
    q.push({0,i});
    while (!q.empty())
    {
    pair<ll,ll>pp=q.top();
    q.pop();
    if (vis[pp.second])
    {
        continue;
    }
    vis[pp.second]=1;
    sol[pp.second-1]=min(sol[pp.second-1],pp.first);
    for (auto el:adj[pp.second])
    {
      q.push({pp.first+el.second,el.first}); 
    }
    }
}
bool valid(ll i,ll j){
    return i<3 && j<3 && i>=0 && j>=0 && !vis[i][j];
}

ll rec(ll l,ll r){
    if ((r+(l/2))==k)
    {
        return 0;
    }
    if (dp[l][r]!=-1)
    {
        return dp[l][r];
    }
    ll lf=rec(l+2,r)+v2[l]+v2[l+1];
    ll rf=rec(l,r+1)+v[r];
    return dp[l][r]=max(lf,rf);
    
   
}
void print(ll i,ll j){
    if (i==j)
    {
        cout<<s[i];
        return;
    }
    if (s[i]==s[j])
    {
        cout<<s[i];
        print(i+1,j-1);
        cout<<s[j];
        return;
    }
    else
    {
        cout<<s[i];
        print(i+1,j);
        cout<<s[i];
        return;
    }
}*/
ll power(ll b,ll n)
    {
        b%=MOD;
        ll s=1;
        while(n)
        {
            if(n%2==1)s=s*b%MOD;
            b=b*b%MOD;
            n/=2;
        }
        return s;
}
bool can(ll md,ll a,ll d,ll w){
    ll t=0;
    ll p=0;
    for (int i = 0; i <n; i++)
    {
        if (t+d<v[i] || p==0)
        {
            t=v[i]+w;
            p=a-1;
            md--;
        }
        else
        {
            p--;
        }
        if (md<0)
        {
            return false;
        }
    }
    return true;
    
}
bool verif(string s1,string s2){
    for (int i = 0; i <s1.length() ; i++)
    {
        if (s1[i]<'5' || s2[i]<'5')
        {
            return false;
        }
    }
    return true;
}
void solve() {
    ll r;
    ll l;
    ll w;
    ll d;
    ll a;
    ll b;
    ll k;
    ll o;
    ll q;
    v.clear();
    v2.clear();
    vv.clear();
    vv2.clear();
    string s;
    string s1;
    string s2;
    map<ll,ll>mp;
    set<ll>st;
    a=0;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        cin>>o;
        v.push_back(o);
    }
    sort(all(v));
    v2=v;
    reverse(all(v));
    vv.push_back(0);
    vv2.push_back(0);
    for (int i = 0; i < n; i++)
    {
        vv.push_back(v[i]);
        vv2.push_back(v2[i]);
    }
    
    for (int i = 1; i < n+1; i++)
    {
        vv[i]+=vv[i-1];
        vv2[i]+=vv2[i-1];
    }
    c=LONG_LONG_MAX;
    for (int i = 0; i <= k; i++)
    {
        c=min(c,vv[i]+vv2[(k-i)*2]);
    }
    
    
    cout<<accumulate(all(v),0ll)-c;
    
    
    
    cout<<endl;
    

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
       // memset(dp,-1,sizeof dp);
         //cout << "Case #" << t << ": ";
        solve();
    }
}